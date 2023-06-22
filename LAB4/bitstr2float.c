// ***************************************
// LAB4: Part 1 - binary float to decimal float rep - Phoebe Spratt(phospra)
// CREATED: 10/10/2022
// **********************************

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if(argc != 2) {
		printf("wrng number of arguments");
		exit(EXIT_FAILURE);
	}
	
	char bin[32];	
	char *in = argv[1];
	for(int i = 0; i <= 32; i++) {bin[i] = in[i];}

	int f = 0;
	int len = strlen(bin);

	if(len == 32) {
		f = 1;

		for(int i = 0; i < 32; i++) {
			if(bin[i] == '0' || bin[i] == '1') {
				f = 1;
			} else {
				f = 0;
				break;
			}
		}
	} else {
		f = 0;
	}


	// f =1 
	if(f == 1) {
		double mant = 0.0;
		double numb = 0;

		int sign = bin[0] - '0';
		int ex = 0; // exponent

		// expojnetn
		for(int i = 8; i > 0; --i) {
			ex += (pow(2, (8 - i))) * (bin[i] - '0');
		}

		// mantessa
		for(int i = 9; i < 32; i++) {
			mant += (1.0 * (bin[i] - '0')) / (pow(2, (i - 8)) * 1.0);
		}

		printf("Sign: %d\n", sign);
		printf("Exponent: %d\n", ex);

		if(ex == 0 && mant == 0) {
			ex = 0;
		} else if(ex == 0 && mant != 0) {
			ex = -126;
		} else if(ex !=0 && mant != 0) {
			ex -= 127;
			mant += 1.0;
		}

		printf("Mantissa: %.17g\n", mant);

		numb = (pow(-1, sign)) * (pow(2, ex)) * mant;
		printf("Number: %.7g\n", numb);
	} else {
		printf("Incorrect input argument\n");	
		exit(EXIT_FAILURE);
	}
}






