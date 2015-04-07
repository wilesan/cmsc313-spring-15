/* File: void_ptr.c

   Using void pointers creates no warnings!
*/
#include <stdio.h>

int main() {
   int *iptr ;
   void *vptr ;
   float x = 3.0 ;

   vptr = & x ;
   iptr = vptr ;
   printf("%d\n", *iptr) ;

   return 0 ;
}
