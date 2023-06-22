// ***************************************
// LAB6: Part 1 - pipe - Phoebe Spratt(phospra)
// CREATED: 12/04/2022
// **********************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	if(argc != 3) {
		printf("wrng number of arguments");
		exit(EXIT_FAILURE);
	}

	int end[2];
	
	if(pipe(end) == -1) {
		fprintf(stderr, "PIPE FAILED");
		return 1;
	}

	write(end[1], argv[1], strlen(argv[1]) + 1);

	char s1[100];
	char s2[100];
	
	read(end[0], s1, 100);
	printf("%s\n", s1);

	write(end[1], argv[2], strlen(argv[2]) + 1);

	read(end[0], s2, 100);
	printf("%s\n", s2);

}
