// ***************************************
// LAB6: Part 1 - execl - Phoebe Spratt(phospra)
// CREATED: 12/04/2022
// **********************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char* argv[]) {
	if(argc != 3) {
		printf("wrng number of arguments");
		exit(EXIT_FAILURE);
	}

	char base[] = "/bin/";
	char *path = strcat(base, argv[1]);

	execl(path, path, argv[2], (char *) NULL);


}
