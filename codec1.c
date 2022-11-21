#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
// Most of the code was adapted from: https://aticleworld.com/c-program-to-convert-uppercase-to-lowercase-in-file/

//toggle file alphanumeric data
void encodeDecodeCodec1(char *str)
/**
     * Function to convert lowercase characters to uppercase
     * and uppercase to lowercase in a file.
     * It also closes the opened file
*/
{
    int len = strlen(str);
    char *temp = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        /*
         * If current character is uppercase then toggle
         * it to lowercase and vice versa.
         */
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                temp[i] = tolower(str[i]);
            } else if (islower(str[i])) {
                temp[i] = toupper(str[i]);
            }
        } else {
            temp[i] = str[i];
        }
    }
    printf("%s\n", temp);
    free(temp);
}
