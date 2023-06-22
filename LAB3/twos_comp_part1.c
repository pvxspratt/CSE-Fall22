// ***************************************
// LAB3: Part 1 - converting ints to 8-bit binary - Phoebe Spratt(phospra)
// CREATED: 09/23/2022
// **********************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if(argc != 2) {
	    printf("wrong number of arguments");
	    exit(EXIT_FAILURE);
    } 

    char *in = argv[1];
    int x = atoi(in);

    if((x < -128) | (x > 127)) { // if can be 8-bit signed number
        printf("integer has to be able to be shown in 8-bit signed number");
        exit(EXIT_FAILURE);	
    }


    // x is positive
    if((x > 0) & (x <= 127)) {
    	int i;
    	int a[10];
	char b[10];
	char padding[10];

    	for(i = 0; x > 0; i++) {
	    a[i] = x % 2;
	    x = x / 2;
    	}

	// if need padding
	if(i != 8) {
		int pad = 0;
		pad = 8 - i;
		//printf("%d\n", pad);
 		for(int j = 0; j < pad; j++) {
			strcat(padding, "0");
		}
	}

	int j=0;
    	for(i = i - 1; i >=0; i--) {
	    j += sprintf(&b[j], "%d", a[i]);    
	}

	strcat(padding, b);
	printf("%s\n", padding);
	
    } else if ((x < 0) & (x >= -128)) {
	int i;
        int a[10];
        char b[10];
        char padding[10];
	int y = x;


        for(i = 0; x > 0; i++) {
            a[i] = x % 2;
            x = x / 2;
        }

        // if need padding
        if(i != 8) {
                int pad = 0;
                pad = 8 - i;
                //printf("%d\n", pad);
                for(int j = 0; j < pad; j++) {
                        strcat(padding, "0");
			//printf("%d", ~0);
                }
        }

        int j=0;
        for(i = i - 1; i >=0; i--) {
            j += sprintf(&b[j], "%d", a[i]);
	    //printf("%d", ~a[i]);
        }

        strcat(padding, b);
        //printf("%s\n", padding);
	    // 	    // add padding
	    // invert it bitwise NOT 
	    // add 1
	for(int i = 7; i >=0; i--) {
		printf("%d", (y&(1<<i)) ? 1 : 0);
	}
	printf("\n");

    }
}










