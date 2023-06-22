// ***************************************
// LAB4: Part 2 - decimal float to binary float rep - Phoebe Spratt(phospra)
// CREATED: 10/09/2022
// **********************************

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// union so all together
typedef union {
	float f;
	
	struct {
		unsigned int mant : 23;
		unsigned int ex : 8;
		unsigned int sign : 1;
	} s;
} all;

int main(int argc, char *argv[]) {
	if(argc > 2) {
		printf("too many arguments\n");
		exit(EXIT_FAILURE);
	} else if(argc == 2) {
		all var;
		var.f = atof(argv[1]);

		printf("%d", var.s.sign);
		int n1 = var.s.ex;
		int i1 = 8;
	       	int n2 = var.s.mant;
		int i2 = 23;

		int k1, k2;
		
		// int to binary
		for(k1 = i1 - 1; k1 >= 0; k1--) {
			if((n1 >> k1) & 1) { 
				printf("1");
			} else {
				printf("0");
			}
		}
		
		// int to binarty
		for(k2 = i2 - 1; k2 >= 0; k2--) {
                        if((n2 >> k2) & 1) {
                                printf("1");
                        } else {
                                printf("0");
                        }
                }

		printf("\n");
	} else {
		printf("No input given\n");
		exit(EXIT_FAILURE);
	}
}
