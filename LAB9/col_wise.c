// ***************************************
// LAB9: Part 1 - col-wise - Phoebe Spratt(phospra)
// CREATED: 12/10/2022
// **********************************

#include <stdio.h>
#define SZ 4

int main() {
	int i,j;
	int A[SZ][SZ];

	for (i = 0; i < SZ; i++) {
		for (j = 0; j < SZ; j++) {
         		A[i][j] = i*j;
       		}
    	}

	for(j = 1; j < SZ; j++) {
		for(i = 0; i<SZ; i++) {
			A[i][j] = (A[i][j-1] + A[i][j]) / 2;
		}
	}

	for(i = 0; i < SZ; i++) {
		for(j= 0; j < SZ; j++) {
			printf("arr[%d][%d] = %d \n", i, j, A[i][j]);
		}
	}



}
