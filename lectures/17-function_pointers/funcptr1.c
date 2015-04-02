/* File: funcptr1.c

   Demonstrating function pointers.

*/

#include <stdio.h>

int add3 (int n) {
   return n + 3 ;
}

int add5 (int n) {
   return n + 5 ;
}


int main() {

   int a, b  ;
   int (* fptr) (int) ;

   a = 7 ;
   printf("a = %d\n", a) ;

   fptr = add3 ;
   b = fptr(a) ;
   printf("fptr(a) = %d\n", b ) ;

   fptr = add5 ;
   b = fptr(a) ;
   printf("fptr(a) = %d\n", b ) ;

   return 0 ;
}
