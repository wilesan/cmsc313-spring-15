/* File: funcptr3.c

   Demonstrating function pointers.

*/


#include <stdio.h>


int diff (int m, int n) {
   return m - n ;
}

int sum (int m, int n) {
   return m + n ;
}

typedef int (* FPTR2) (int, int) ;

void do_array(int A[], int B[], int size, FPTR2 fptr) {
   int i ;

   for ( i = 0 ; i < size ; i++) {
      A[i] = (* fptr) (A[i], B[i]) ;
   }
}


int main() {

   int A[10], B[10], i  ;

   for (i = 0 ; i < 10 ; i++) {
      A[i] = i * i ; 
      B[i] = 2 * i ;
   }

   printf("Original arrays:\n") ;
   for (i = 0 ; i < 10 ; i++) {
      printf("A[%d] = %d,   B[%d] = %d\n", i, A[i], i, B[i])  ; 
   }

   do_array(A, B, 10, &diff) ;

   printf("\n\n After calling do_array(A, B, 10, &diff):\n") ;
   for (i = 0 ; i < 10 ; i++) {
      printf("A[%d] = %d,   B[%d] = %d\n", i, A[i], i, B[i])  ; 
   }

   do_array(A, B, 10, &sum) ;

   printf("\n\n After calling do_array(A, 10, &sum):\n") ;
   for (i = 0 ; i < 10 ; i++) {
      printf("A[%d] = %d,   B[%d] = %d\n", i, A[i], i, B[i])  ; 
   }

   return 0 ;
}
