// ***************************************
// LAB6: Part 2 - subprocesses and linux binaries - Phoebe Spratt(phospra)
// CREATED: 12/04/2022
// **********************************

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
	if(argc > 3) {
		printf("Too many args.\n");
		exit(EXIT_FAILURE);
	}

	int fd[2];
	if(pipe(fd) < 0) {
		printf("pipe fail\n");
		exit(EXIT_FAILURE);
	}

	int id = fork();
	char path[50];
	char bin[50] = "/bin/";
	char exec[50];
	if(id < 0) {
		printf("Fork id fail\n");
		exit(EXIT_FAILURE);
	} else if(id > 0) {
		write(fd[1], argv[1], 50);
		write(fd[1], argv[2], 50);
		int exitc;
		wait(&exitc);
		close(fd[0]);
		close(fd[1]);
		if(exitc!= 0) {
			printf("Child fail.\n");
			exit(EXIT_FAILURE);
		}
	} else {
		read(fd[0], path, 50);
		read(fd[0], exec, 50);
		char* bs;
		if(*(bs = strstr(path, "/bin/")) == '\0') {
			strcat(bin, path);
			if(execl(bin, path, exec, NULL) != 0) {
				exit(EXIT_FAILURE);
			}
		} else {
		
			if(execl(path, path + 5, exec, NULL) != 0) {
				exit(EXIT_FAILURE);
			}
		}
	}

	exit(EXIT_SUCCESS);

}
