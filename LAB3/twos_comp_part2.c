// ***************************************
// LAB3: Part 2 - 8-bit binary to un/signed integers - Phoebe Spratt(phospra)
// CREATED: 09/30/2022
// **********************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[]) {
    if(argc != 3) {
	    printf("wrong number of arguments");
	    exit(EXIT_FAILURE);
    }

    char *in = argv[1];
//    int x = atoi(in);
    
    if(strcmp(argv[2], "signed") == 0) {
//int x = atoi(in);
    	   // printf("x %d\n", x);
	//char *inverse = argv[1];
	//int y = atoi(inverse);
	
	for(int i = 0; i < 8; i++) {
		in[i] = !(in[i] - 48); //inverse
		//inverse[i] = !(inverse[i] - 48);
	}

	char a[10];
	int j = 0;
	//int intarr[10];

	//printf("\n inverse  ");
	for(int i = 0; i < 8; i++) {
          //      printf("%d", in[i]); //inverse
		j += sprintf(&a[j], "%d", in[i]);
	//	intarr[i] = atoi(&a[i]);
		//printf("%d", inverse[i]);
        }

//	for(int i=0;i<8;i++) {
//		printf("

	int res = atoi(a);
	//printf("\n");
	//printf("inveres as a char arr %s\n", a);
	//printf("%d\n", res);
	
	
	char padding[10];
	if(res!=8) {
		int pad = 0;
		pad = 8-res;
		for(int j = 0; j <pad; j++) {
			strcat(padding,"0");
		}
	}

	strcat(padding,a);
	//printf("pads %s\n", padding);
	int ans = atoi(padding);

	int m = 1;
        while(ans&m) {
                ans = ans ^ m;
                m <<= 1;
                //m >>= 1;
        }
        ans = ans ^m;
        //printf("add one %d\n", ans);



	int d = 0;
	int i = 0;
	int r;

	while(ans!=0) {
		r = ans %10;
		ans /= 10;
		d += r * pow((double)2,(double) i);
		i++;
	}
	
	printf("%d", ~d+1);
	printf("\n");




    } else if(strcmp(argv[2], "unsigned") == 0) {
	int x = atoi(in);

	    int d = 0;
        int i = 0;
        int r;

        while(x!=0) {
                r = x %10;
                x /= 10;
                d += r * pow((double)2,(double) i);
                ++i;
        }

        printf("%d", d);
        printf("\n");

    } else {
	    printf("enter signed or unsigned");
            exit(EXIT_FAILURE);
    }

}
