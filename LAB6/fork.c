// ***************************************
// LAB6: Part 1 - fork, pipe, and execl - Phoebe Spratt(phospra)
// CREATED: 12/04/2022
// **********************************

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int var;

int main(int argc, char* argv[]) {
	if(argc != 2) {
		printf("wrng number of arguments");
		exit(EXIT_FAILURE);
	}

	var = atoi(argv[1]);

	if(fork() == 0) {
		printf("Hello World\n");
		printf("Child: %d\n", var - 1);
	} else {
		printf("Hello World\n");
		printf("Parent: %d\n", var + 1);
	}

}
