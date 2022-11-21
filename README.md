# OperatingSystems_Assignment1


## How to run the code
```
Script started on 2022-11-17 13:12:02-08:00 [TERM="xterm-256color" TTY="/dev/pts/1" COLUMNS="116" LINES="40"]
]0;appeldaniel@ubuntu: ~/CLionProjects/OperatingSystems_Assignment1-1[01;32mappeldaniel@ubuntu[00m:[01;34m~/CLionProjects/OperatingSystems_Assignment1-1[00m$ make all
gcc -Wall -g -c codec2.c -ldl
gcc -shared -o codec2.so codec2.o -ldl
gcc -Wall -g -c codec1.c -ldl
gcc -shared -o codec1.so codec1.o -ldl
gcc -Wall -g -c encode.c -ldl
gcc -Wall -g -o encode encode.o ./codec1.so ./codec2.so -lm -ldl
gcc -Wall -g -c decode.c -ldl
gcc -Wall -g -o decode decode.o ./codec1.so ./codec2.so -lm -ldl
gcc -Wall -g -c copy.c
gcc -Wall -g -o copy copy.o
gcc -Wall -g -c cmp.c
gcc -Wall -g -o cmp cmp.o
]0;appeldaniel@ubuntu: ~/CLionProjects/OperatingSystems_Assignment1-1[01;32mappeldaniel@ubuntu[00m:[01;34m~/CLionProjects/OperatingSystems_Assignment1-1[00m$ ./cmp File1.txt File2.txt
Identical
]0;appeldaniel@ubuntu: ~/CLionProjects/OperatingSystems_Assignment1-1[01;32mappeldaniel@ubuntu[00m:[01;34m~/CLionProjects/OperatingSystems_Assignment1-1[00m$ ./cmp File1.txt File3.txt
Not identical
]0;appeldaniel@ubuntu: ~/CLionProjects/OperatingSystems_Assignment1-1[01;32mappeldaniel@ubuntu[00m:[01;34m~/CLionProjects/OperatingSystems_Assignment1-1[00m$ ./copy File1.txt File2.txt
]0;appeldaniel@ubuntu: ~/CLionProjects/OperatingSystems_Assignment1-1[01;32mappeldaniel@ubuntu[00m:[01;34m~/CLionProjects/OperatingSystems_Assignment1-1[00m$ ./encode codec1 LALAlala223344
lalaLALA223344
]0;appeldaniel@ubuntu: ~/CLionProjects/OperatingSystems_Assignment1-1[01;32mappeldaniel@ubuntu[00m:[01;34m~/CLionProjects/OperatingSystems_Assignment1-1[00m$ ./encode codec2 LALAlala223344
Ž¿Ž¿ÎÎÍÍÌÌ
]0;appeldaniel@ubuntu: ~/CLionProjects/OperatingSystems_Assignment1-1[01;32mappeldaniel@ubuntu[00m:[01;34m~/CLionProjects/OperatingSystems_Assignment1-1[00m$ ./decode codec1 LALAlala223344
lalaLALA223344
]0;appeldaniel@ubuntu: ~/CLionProjects/OperatingSystems_Assignment1-1[01;32mappeldaniel@ubuntu[00m:[01;34m~/CLionProjects/OperatingSystems_Assignment1-1[00m$ ./decode codec1 LALAlala223344[C[1P LALAlala2233442 LALAlala223344
Ž¿Ž¿ÎÎÍÍÌÌ
]0;appeldaniel@ubuntu: ~/CLionProjects/OperatingSystems_Assignment1-1[01;32mappeldaniel@ubuntu[00m:[01;34m~/CLionProjects/OperatingSystems_Assignment1-1[00m$ exit
exit

Script done on 2022-11-17 13:13:22-08:00 [COMMAND_EXIT_CODE="0"]
```


## The URL we used
### For cmp.c:
* https://www.geeksforgeeks.org/c-program-compare-two-files-report-mismatches/
* https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
### For copy.c:
* https://stackoverflow.com/questions/9219079/copying-contents-of-a-file-to-another-using-read-write-open
* https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
* https://stackoverflow.com/questions/3984948/how-to-figure-out-if-a-file-is-a-link
* https://www.geeksforgeeks.org/getopt-function-in-c-to-parse-command-line-arguments/
* https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-readlink-read-value-symbolic-link
* https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-symlink-create-symbolic-link-path-name
### For encode.c:
* https://tldp.org/HOWTO/Program-Library-HOWTO/dl-libraries.html
### For codec1.c:
* https://aticleworld.com/c-program-to-convert-uppercase-to-lowercase-in-file/








דוגמה איך להפעיל את הקוד ואת הurl של האתרים 
שלקחנו  מהם קודים
