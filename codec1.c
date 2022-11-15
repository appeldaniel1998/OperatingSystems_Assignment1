#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
// Most of the code was adapted from: https://aticleworld.com/c-program-to-convert-uppercase-to-lowercase-in-file/

//toggle file alphanumeric data
void toggleFileData(char *argv[])
/**
     * Function to convert lowercase characters to uppercase
     * and uppercase to lowercase in a file.
     * It also closes the opened file
*/
{
    //file pointer
    FILE *fptr = NULL;
    //open the file
    fptr = fopen(argv[1], "r");
    if(fptr == NULL)
    {
        printf("Error in creating the file\n");
        exit(1);
    }

    FILE *fpTmp = NULL;
    int ch = 0;
    //open the file
    fpTmp = fopen("tmp.txt", "w");
    if(fpTmp == NULL)
    {
        printf("Error in creating tmp file\n");
        fclose(fptr);
        exit(1);
    }
    //until EOF
    while ( (ch = fgetc(fptr)) != EOF)
    {
        /*
         * If current character is uppercase then toggle
         * it to lowercase and vice versa.
         */
        if (isalpha(ch)) ch = (isupper(ch))? tolower(ch):toupper(ch);
        // write ch in temporary file.
        fputc(ch, fpTmp);
    }
    // Close all files to release resource
    fclose(fptr);
    fclose(fpTmp);
    // Delete original file
    remove(argv[1]);
    // Rename temporary file as original file
    rename("tmp.txt", argv[1]);
}
