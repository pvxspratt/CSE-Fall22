// ***************************************
// LAB1: Part 2 - countring total number of words - Phoebe Spratt(phospra)
// CREATED: 09/02/2022
// **********************************

#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[]) {
    FILE *file;
    char* ptr;

    int count = 0;
    char *buff = NULL;
    size_t buffSize = 0;

    clock_t start, end;
    double time;
    ssize_t lineSize;

    if(argc != 5) {
	printf("wrong number of arguments");
	exit(EXIT_FAILURE);
    }

    // start time
    start = clock();

    // open tsv file
    file = fopen(argv[1], "r");
    if(!file) {
	fprintf(stderr, "problem opening file");
	exit(EXIT_FAILURE);
    }

    
    lineSize = getline(&buff, &buffSize, file);
    while(lineSize >= 0) {
        ptr = strstr(buff, argv[2]);
	    	
        while(ptr != NULL) {
            ++count;
            ptr = strstr(ptr+1, argv[2]);
        } 
        
	lineSize = getline(&buff, &buffSize, file);
    }
    
    printf("%s Count: %d\n", argv[2], count);
    fclose(file);
    free(buff);

    count = 0; // reset count

    // open enwik9 file
    file = fopen(argv[3], "r");
    if(!file) {
        fprintf(stderr, "problem opeing file");
	exit(EXIT_FAILURE);
    }

    lineSize = getline(&buff, &buffSize, file);
    while(lineSize >= 0) {
        ptr = strstr(buff, argv[4]);

        while(ptr != NULL) {
            ++count;
            ptr = strstr(ptr+1, argv[4]);
        }

        lineSize = getline(&buff, &buffSize, file);
    }

    printf("%s Count: %d\n", argv[4], count);
    fclose(file);

    free(buff);

    end = clock();
    time = (double) (end - start);
    file = fopen("README.md", "w+");
    fprintf(file, "time: %lf", time);
    fclose(file);
}
