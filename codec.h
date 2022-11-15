
#include "codec1.c"
#include "codec2.c"

#ifndef OPERATINGSYSTEMS_ASSIGNMENT1_CODEC_H
#define OPERATINGSYSTEMS_ASSIGNMENT1_CODEC_H

/// Declaration on functions in CODEC1,2


void encodeCodec1(char *src, char *dst, int len) {

};

void decodeCodec1(char *src, char *dst, int len) {

};

void encodeCodec2(char *src, char *dst, int len) {
    encodeDecodeCodec2(src, dst, len);
};

void decodeCodec2(char *src, char *dst, int len) {
    encodeDecodeCodec2(src, dst, len);
};


#endif //OPERATINGSYSTEMS_ASSIGNMENT1_CODEC_H
