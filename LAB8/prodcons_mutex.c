// ***************************************
// LAB8: Part 2 - improved prod/con - Phoebe Spratt(phospra)
// CREATED: 12/08/2022
// **********************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

//int main() {
//	int randNum;
//	srand(time(NULL));
//	randNum = rand() % 100;
//	printf("%d\n", randNum);
//	return 0;
//}

int count = 0;
pthread_mutex_t r_mutex;
pthread_mutex_t w_mutex;

void *threadFunc() {
    int i;
    for (i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&r_mutex);
        printf("writer wrote: %d\n", count);
        count++;        
        pthread_mutex_unlock(&w_mutex);
    }
    
    return NULL;
}

int main(void) {
    pthread_t t1;
    
    // Initialize mutexes
    pthread_mutex_init(&r_mutex, NULL);
    pthread_mutex_init(&w_mutex, NULL);
    pthread_mutex_lock(&w_mutex);
    
    pthread_create(&t1, NULL, threadFunc, NULL);
    
    int i;
    for (i = 0; i < 10; i++) {
        pthread_mutex_lock(&w_mutex);
        printf("main read: %d\n", count);
        count++;
        pthread_mutex_unlock(&r_mutex);
    }
    
    pthread_join(t1, NULL);
    
    pthread_mutex_destroy(&r_mutex);
    pthread_mutex_destroy(&w_mutex);
    
    return 0;
}
