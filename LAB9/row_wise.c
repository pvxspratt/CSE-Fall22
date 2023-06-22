// ***************************************
// LAB9: Part 1 - interchange row-wise - Phoebe Spratt(phospra)
// CREATED: 12/10/2022
// **********************************

#include <stdio.h>
#define SZ 4

int main() {
        int A[SZ][SZ];
	
        for(int i =  0; i < SZ; i++) {
      	    for(int j = 0; j < SZ; j++) {
    		A[i][j] = i*j;
	    }  
        }

	for(int i = 0; i < SZ; i++) {
		for( int j = 1; j < SZ; j++) {
			A[i][j] = (A[i][j-1] + A[i][j]) / 2;
		}
	}

	for(int i = 0; i < SZ; i++) {
		for(int j = 0; j < SZ; j++) {
			printf("A[%d][%d] = %d \n", i, j, A[i][j]);
		}
	}


}
