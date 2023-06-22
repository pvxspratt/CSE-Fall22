// ***************************************
// LAB8: Part 1 - naive prod/con - Phoebe Spratt(phospra)
// CREATED: 12/08/2022
// **********************************

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int randNum;
	srand(time(NULL));
	randNum = rand() % 100;
	printf("%d\n", randNum);
	return 0;
}
