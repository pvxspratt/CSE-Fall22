// ***************************************
// LAB7: Part 2 - multi-thread implem - Phoebe Spratt(phospra)
// CREATED: 12/07/2022
// **********************************

#define _POSIX_C_SOURCE 200809L
#define NTHREADS 2
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct input_args  {
	char* a;
	char* b;
};

typedef struct input_args IA;

void* file_read(void *arg) {
	IA* args = (IA*) arg;
	FILE *fp;
	char *buffer = NULL;
	char* tempbuffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;
	int count=0;
	fp = fopen(args->a, "r");
	if(fp == NULL) {
		exit(EXIT_FAILURE);
	}

	while((characters = getline(&buffer, &bufsize, fp) != -1)) {
		tempbuffer = buffer;
		while((tempbuffer = strstr(tempbuffer, args->b)) != NULL) {
			count +=1;
			*tempbuffer = *tempbuffer + strlen(args->b);
		}
	}
    
	fclose(fp);
	printf("%s Count: %d\n", args->b, count);
	return NULL;
}


int main(int argc, char* argv[]) {
	if(argc != 5 ) {
		exit(EXIT_FAILURE);
	}

	pthread_t tid[NTHREADS];

	IA arg1 = {.a = argv[1], .b = argv[2]};
	pthread_create(&tid[0], NULL, file_read, (void*) &arg1);

	IA arg2 = {.a = argv[3], .b = argv[4]};
	pthread_create(&tid[1], NULL, file_read, (void*) &arg2);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	exit(EXIT_SUCCESS);
}
