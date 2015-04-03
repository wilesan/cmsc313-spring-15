/* File: qsort1.c

   Demonstrating use of callback functions in qsort().
*/

#include <stdio.h>
#include <stdlib.h>


typedef int (* COMP_FUNC_PTR) (const void *, const void *) ;

int lessthan (int *ptr1, int *ptr2) {
   return *ptr1 - *ptr2 ;
}

int main() {
  int A[25] = {  2,  7, 91, 23, 14, 72, 19, 31, 44, 62,
                34, 11, 51, 62, 22, 81, 45, 54, 67, 74,
                24, 15, 41, 83, 88} ;
   int i ;

   printf("Original array:\n") ;
   for (i = 0 ; i < 25 ; i++) {
      printf("  A[%d] = %d\n", i, A[i]) ;
   }

   qsort(A, 25, sizeof(int), (COMP_FUNC_PTR) &lessthan) ;

   printf("\n\nSorted array:\n") ;
   for (i = 0 ; i < 25 ; i++) {
      printf("  A[%d] = %d\n", i, A[i]) ;
   }

   return 0 ;
}
