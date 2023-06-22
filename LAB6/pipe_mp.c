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
	if(argc != 2) {
		printf("wrng number of arguments");
		exit(EXIT_FAILURE);
	}

	int end[2];
	pid_t p;

	if(pipe(end) == -1) {
		fprintf(stderr, "PIPE FAIELD");
		return 1;
	}

	p = fork();

	if(p < 0) {
		fprintf(stderr, "FORK FAILED");
		return 1;
	} else if(p > 0) { // parent
		close(end[0]);
		write(end[1], argv[1], strlen(argv[1]) + 1);
		close(end[1]);
	} else { //child
		close(end[1]);

		char str[100];
		read(end[0], str, 100);
		printf("%s\n", str);
	}


}
