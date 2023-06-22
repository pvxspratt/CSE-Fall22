#include "bitops.h"
#include <stdio.h>

/*
 * Return and of x and y
 * Points: 3
 */
int and_op(int x, int y) {
  return x&y;
}

/* 
 * Return or of x and y
 * Points: 3
 */
int or_op(int x, int y) {
  return x|y;
}

/*
 * Return xor of x and y
 * Points: 3
 */
int xor_op(int x, int y) {
  return x^y;
}


/*
 * Clear `b`th byte of x
 * Points: 7
 */
int masking_and(int x, int b) {
  	if(x < 0) {
		return 0;
	}

	unsigned int masking = ~(0xff << 8 * (32 - b));
	return x&masking;
}

/*
 * Set `b`th byte of x
 * Points: 7
 */
int masking_or(int x, int b) {
        unsigned int masking = (0xff << 8 * (32 - b));
        return x|masking;
}

/*
 * Toggle `b`th byte of x
 * Points: 7
 */
int masking_xor(int x, int b) {
  	int size = sizeof(x);
        unsigned int masking = (0xff << 8 * (size - b));
        return x^masking;
}

/*
 * Shift x to the left by `sc` # of bits
 * Points: 3
 */
int shifting_left_op(int x, int sc) {
     	unsigned int shift = (x << sc) | (x >> (32 - sc));
	return shift;
}

/*
 * Shift x to the right by `sc` # of bits
 * Points: 3
 */
int shifting_right_op(int x, int sc) {
  	unsigned int shift = (x >> sc) | (x << (32 - sc));
	return x >> shift;
}


/*
 * Return logical not of x
 * Points: 3
 */
int bang(int x) {
  return !x;
}

/*
 * Print binary string representation for x
 * Points: 30
 */
void bit_conversion(int x) {
	int a[10];
	int i;
	for(i = 0; x > 0; i++) {
		a[i] = x % 2;
		x = x / 2;	
	}

	
	for(i = i - 1; i >=0; i--) {
		printf("%d", a[i]);
	}

	printf("\n");
}


