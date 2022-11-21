 #include <stdlib.h>
 #include <stdio.h>
 #include <dlfcn.h>

# encode.c, decode.c, codec1.c codec2.c codec.h, cmp.c , copy.c
CC = gcc
FLAGS = -Wall -g
AR= ar
LDFLAGS = -ldl


# Make all must make all binaries.
# Make clean must delete all craft


#make all
all:Codec2 Codec1 encode decode copy cmp


cmp: cmp.o
	$(CC) $(FLAGS) -o cmp cmp.o

cmp.o: cmp.c
	$(CC) $(FLAGS) -c cmp.c

# make dynamic - codec1.s
# make dynamic
copy: copy.o
	$(CC) $(FLAGS) -o copy copy.o


copy.o: copy.c
	$(CC) $(FLAGS) -c copy.c

#codec1.so : Encoder converts uppercase chars to lowercase and vise versa. Doesn’t change all other chars.

#codec2.so : Encoder calculates NEG value of each char.

# make encode dynamic
encode: encode.o codec2.so codec1.so
		$(CC) $(FLAGS) -o encode encode.o ./codec1.so ./codec2.so -lm $(LDFLAGS)

# make decode dynamic
decode: decode.o codec2.so codec1.so
		$(CC) $(FLAGS) -o decode decode.o ./codec1.so ./codec2.so -lm $(LDFLAGS)

# dynamic library
Codec2: codec2.o
	$(CC) -shared -o codec2.so codec2.o $(LDFLAGS)
# dynamic library
Codec1: codec1.o
	$(CC) -shared -o codec1.so codec1.o $(LDFLAGS)

codec2.o: codec2.c codec.h
	$(CC) $(FLAGS) -c codec2.c $(LDFLAGS)

codec1.o: codec1.c codec.h
	$(CC) $(FLAGS) -c codec1.c $(LDFLAGS)

encode.o: encode.c codec.h
	$(CC) $(FLAGS) -c encode.c $(LDFLAGS)

decode.o: decode.c codec.h
	$(CC) $(FLAGS) -c decode.c $(LDFLAGS)

#make clean
.PHONY: clean all

 clean:
	rm -f encode decode copy cmp *.a *.so *.o

