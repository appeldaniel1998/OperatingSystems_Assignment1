#include <stdio.h>

void encodeDecodeCodec2(char *src, char *dst, int len) {
    for (int i = 0; i < len; i++) {
        dst[i] = (char) -src[i];
    }
    printf("%s", src);
}
