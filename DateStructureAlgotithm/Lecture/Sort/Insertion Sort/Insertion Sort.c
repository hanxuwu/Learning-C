
// Insertion sort from week1a 

#include <stdio.h> // include standard I/O library defs and functions

#define SIZE 6     // define a symbolic constant

void insertionSort(int array[], int n) {  // function headers must provide types
   int i;                                 // each variable must have a type
   for (i = 1; i < n; i++) {              // for-loop syntax
      int element = array[i];                                                    
      int j = i-1;
      while (j >= 0 && array[j] > element) {   // logical AND
         array[j+1] = array[j];
         j--;                                 // abbreviated assignment j=j-1 
      }
      array[j+1] = element;                   // statements terminated by ;
   }                                          // code blocks enclosed in { } 
}

int main(void) {                              // main: program starts here
   int numbers[SIZE] = { 3, 6, 5, 2, 4, 1 };  /* array declaration
                                                 and initialisation */
   int i;
   insertionSort(numbers, SIZE);
   for (i = 0; i < SIZE; i++)
      printf("%d\n", numbers[i]);             // printf defined in <stdio>

   return 0;           // return program status (here: no error) to environment
}