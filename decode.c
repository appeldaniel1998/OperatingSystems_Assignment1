#include <string.h>
#include <dlfcn.h>
#include "codec.h"

int main(int argc, char *argv[]) {
    char libPath[12];//Define array in size 10
    libPath[0] = '.';
    libPath[1] = '/';
    for (int i = 2; i < 8; i++)//we will
    {
        libPath[i] = argv[1][i-2];
    }
    libPath[8] = '.';
    libPath[9] = 's';
    libPath[10] = 'o';
    libPath[11] = '\0';

    void *handle = dlopen(libPath, RTLD_NOW); //Gain access to a dynamic link library.loads the dynamic shared object (shared library) file
    void (*fptr)(char *str, char *dst, int len);

    int len = strlen(argv[2]);
    char *dest = malloc(len * sizeof(char));
    if (strcmp(argv[1], "codec1") == 0) {
        //dlsym() takes a "handle" of a dynamic library returned by dlopen() and the null-terminated symbol name, returning the address where that symbol is loaded into memory.
        fptr = dlsym(handle, "encodeDecodeCodec1"); //find the address of function and data objects */
        fptr(argv[2], dest, len);
    }
    if (strcmp(argv[1], "codec2") == 0) {
        fptr = dlsym(handle, "encodeDecodeCodec2"); //find the address of function and data objects */
        fptr(argv[2], dest, len);
    }
    free(dest);
    //decrements the reference count on the dynamic library handle.
    if (dlclose(handle)!=0) //returns 0 on success
    {
        printf("error\n");
    }
    return 0;
}