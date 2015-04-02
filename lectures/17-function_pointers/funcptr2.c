/* File: funcptr2.c

   Demonstrating function pointers.

*/

#include <stdio.h>

int add3 (int n) {
   return n + 3 ;
}

int add5 (int n) {
   return n + 5 ;
}

typedef int (* INT_INT_FPTR) (int) ;

void do_array(int A[], int size, INT_INT_FPTR fptr) {
   int i ;

   for ( i = 0 ; i < size ; i++) {
      A[i] = (* fptr) (A[i]) ;
   }
}


int main() {

   int A[10], i  ;

   for (i = 0 ; i < 10 ; i++) {
      A[i] = i * i ; 
   }

   printf("Original array A[]:\n") ;
   for (i = 0 ; i < 10 ; i++) {
      printf("A[%d] = %d\n", i, A[i])  ; 
   }

   do_array(A, 10, &add3) ;

   printf("\n\n After calling do_array(A, 10, &add3):\n") ;
   for (i = 0 ; i < 10 ; i++) {
      printf("A[%d] = %d\n", i, A[i]) ; 
   }

   do_array(A, 10, &add5) ;

   printf("\n\n After calling do_array(A, 10, &add5):\n") ;
   for (i = 0 ; i < 10 ; i++) {
      printf("A[%d] = %d\n", i, A[i]) ; 
   }

   return 0 ;
}
