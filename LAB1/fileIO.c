// ***************************************
// LAB1: Part 1 - counting lines with the word - Phoebe Spratt(phospra)
// CREATED: 09/02/2022
// **********************************
#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    FILE *bigFile;
    char* ptr;
    int count = 0;

    char *buff = NULL;
    size_t buffSize = 0;
    ssize_t lineSize;

    if(argc != 3) {
        printf("wrong nubmer of arguments");
	exit(EXIT_FAILURE);
    }

    // open file big.txt
    bigFile = fopen(argv[1], "r");
    if(!bigFile) {
	fprintf(stderr, "problem opening file");
	exit(EXIT_FAILURE);
    }

    // read the file line by line and search for substring Holmes
    lineSize = getline(&buff, &buffSize, bigFile);

    while(lineSize >= 0) {
	ptr = strstr(buff, argv[2]);
        if(ptr) {
            ++count;
	}

	lineSize = getline(&buff, &buffSize, bigFile);
    }

    printf("%d\n", count);
    free(buff);
    fclose(bigFile);
}
