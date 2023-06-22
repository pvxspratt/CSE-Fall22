// ***************************************
// LAB0: Part 4 - Practice Standard I/O - Phoebe Spratt(phospra)
// CREATED: 08/26/2022
// **********************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

int main (int argc, char* argv[]) {
    char scanInput[SIZE];
    FILE *fPtr; // fPtr is my txt file pointer

  //  if (argc > 3 || argc < 2) {
    //  printf("Error: Incorrect num of arguments\n");
   //   exit(EXIT_FAILURE);
   // } 
   
    if (argc == 3) {
      // if it is printf
      if (strcmp(argv[1], "printf") == 0) {
        printf("You entered: %s\n", argv[2]);
        exit(EXIT_SUCCESS);
      }

      // if it is fprintf
      if (strcmp(argv[1], "fprintf") == 0) {
        if((fPtr = fopen("print.txt", "w")) == NULL) {
          exit(EXIT_FAILURE);
        } else {
          while (!feof(stdin)) {
            fprintf(fPtr, "%s\n", argv[2]);
            fclose(fPtr);
            exit(EXIT_SUCCESS);
          }
        }
      }
    } else if (argc == 2) {
      // if it is scanf
      if (strcmp(argv[1], "scanf") == 0) {
        printf("Please enter your input: ");
        scanf("%s", scanInput);
        printf("You put: %s\n", scanInput);
        exit(EXIT_SUCCESS);
      }    
    } else {
      printf("Error: Incorrect num of arguments\n");
      exit(EXIT_FAILURE);
    }
}

