// ***************************************
// LAB0: Part 2 - Exit Status - Phoebe Spratt(phospra)
// CREATED: 08/26/2022
// **********************************

#include <stdio.h>
#include <stdlib.h>

int main (void) {
    fprintf(stderr, "%s", "We want this program to fail\n");
    exit(EXIT_FAILURE);
}

