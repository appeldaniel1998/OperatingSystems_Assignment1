#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

// ln -s File1.txt symLinkTest.txt   - crate symlink (command in terminal which was run for testing purposes)

/*
 * 2.Write a copy file program. Use file descriptor API (open(2), read(2), write(2), close(2))
 * Usage : copy <file1><file2>
 * Output : file is copied. Or “Usage : copy <file1> <file2>”.
 * 3.Support copying of symbolic links in copy. Use -l to copy link contents. Without -l copy the file linked by the symbolic link. Use readlink(2), stat(2), getopt(3)
 * note: -l means lower case 'L'
 *
 * Most of the code for the deepCopy function was adapted from:
 * https://stackoverflow.com/questions/9219079/copying-contents-of-a-file-to-another-using-read-write-open
 * The command line arguments implementation was adapted from:
 * https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
*/

void deepCopy(char pathFile1[], char pathFile2[]) {
    int PATH_MAX = 256;
    char *fullPath1 = malloc(PATH_MAX * sizeof(char));// We will allocate memory to the full paths of both files
    char *fullPath2 = malloc(PATH_MAX * sizeof(char));
    realpath(pathFile1, fullPath1);// if the path is not a full path (i.e. not start with '\' than we will create the full path.


    realpath(pathFile2, fullPath2);

    struct stat sb;  // Find file size in bytes
    stat(fullPath1, &sb);

    int bufSize = sb.st_size;
    char buf[bufSize];
    int destFile, scrFile;
    // output file opened or created
    if ((destFile = open(fullPath2, O_CREAT | O_APPEND | O_RDWR, 0666)) == -1) {
        perror("open");
    }
    // let us open the input file
    scrFile = open(fullPath1, O_RDONLY);
    if (scrFile > 0) { // there are things to read from the input
        read(scrFile, buf, bufSize);
        write(destFile, buf, bufSize);
        close(scrFile);
    }

    close(destFile);
    close(scrFile);

    free(fullPath1); // Free the memory
    free(fullPath2);
}

int pathIsLink(char *argv[]) {
    //Function checks if a file is a link.
    // We use the link : https://stackoverflow.com/questions/3984948/how-to-figure-out-if-a-file-is-a-link
    struct stat buff;
    lstat(argv[1], &buff);
    if (S_ISLNK(buff.st_mode)) {
        return 1;
    } //It is a link
    else { // if (S_ISREG(buff.st_mode))
        return 0;
    } //It is not a link (i.e. it is a file)
}

int isCopyLink(int argc, char *argv[])
//Function check if there is '-l' in the link
//We use the link: https://www.geeksforgeeks.org/getopt-function-in-c-to-parse-command-line-arguments/
{
    int opt;
    opt = getopt(argc, argv, ":if:lrx");
    if (opt == 'l') return 1;
    else if (opt == -1) return 0;
    else {
        printf("Usage : copy <file1> <file2>\n");
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    remove(argv[2]); //If the file already exist we will delete it, so there will be no duplications of file contents.
    int islink = pathIsLink(argv);
    if (islink == 1) { // if it is a link
        int isThereL = isCopyLink(argc, argv); // we will use getopt() to check if there is '-l' in the link
        // Use the link: https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-readlink-read-value-symbolic-link
        int bufSize = 256;
        char *buf = malloc(bufSize * sizeof(char));
        int linkSize = readlink(argv[1], buf, bufSize);
        if (linkSize < 0) perror("readlink() error");
        else
            // Now we will allocate memory to the path to file stored in the symbolic link, and then asign the path.
            // Code below adapted from: https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-symlink-create-symbolic-link-path-name
        {
            while (linkSize + 1 == bufSize) {
                free(buf);
                bufSize *= 2;
                buf = malloc(bufSize * sizeof(char));
                linkSize = readlink(argv[1], buf, bufSize);
            }
            buf[linkSize] = '\0';

            if (isThereL == 1) // If there is '-l', we will go the link and copy it
            {
                if (symlink(buf, argv[2]) != 0) {
                    perror("symlink() error");
                    unlink(argv[2]);
                }
                // else successful in writing symlink
            } else // If there is no '-l', we will go the link and copy the content of the file
            {
                deepCopy(buf, argv[2]); // When buf is the path to the file
            }
        }
    } else { // if not a link, we will copy the content of the file
        deepCopy(argv[1], argv[2]);
    }
    return 0;
}
