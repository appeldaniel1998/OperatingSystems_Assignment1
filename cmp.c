#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*1.Write a compare file program. Use FILE * API to read and compare the files.
 * <Usage : cmp <File1.txt> <file2
 * Output : “Identical\n” or “Not identical\n or “Usage : cmp <File1.txt> <file2>”.
 *
 * Most of the code in this file was adapted from:
 * https://www.geeksforgeeks.org/c-program-compare-two-files-report-mismatches/
 * The command line arguments implementation was adapted from:
 * https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
*/

void compareFiles(FILE *file1, FILE *file2) {
    char ch1 = getc(file1);//initial the variable by getting the first chars
    char ch2 = getc(file2);
    if (ch1 != ch2) {
        printf("Not identical\n");
        return;
    }
    while (ch1 != EOF && ch2 != EOF) //if one of the files end before the other one
    {
        ch1 = getc(file1);
        ch2 = getc(file2);
        if (ch1 != ch2) {
            printf("Not identical\n");
            return;
        }
    }
    printf("Identical\n");//if the entire chars are the same
}

int main(int argc, char *argv[]) {
    if (argc != 3) { // 2 for arguments we get in command line and the last for the 'NULL' argument (not given)
        printf("Usage : cmp <file1> <file2>");
        exit(0);
    }
    FILE *file1 = fopen(argv[1], "r");//read the first path of the file we get from the user
    FILE *file2 = fopen(argv[2], "r");//read the second path of the file we get from the user
    // test for files not existing.
    if (file1 == NULL || file2 == NULL) {
        printf("Usage : cmp <file1> <file2>");
        exit(0);
    }
    compareFiles(file1, file2);
    fclose(file1);
    fclose(file2);
    return 0;
}
