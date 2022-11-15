#include <string.h>
#include "codec.h"

int main(int argc, char *argv[]) {
    int len = strlen(argv[2]);
    char *dest = malloc(len * sizeof(char));
    if (strcmp(argv[1], "codec1") == 0) {
        decodeCodec1(argv[2], dest, len);
    }
    if (strcmp(argv[2], "codec2") == 0) {
        decodeCodec2(argv[2], dest, len);
    }
    free(dest);
    return 0;
}