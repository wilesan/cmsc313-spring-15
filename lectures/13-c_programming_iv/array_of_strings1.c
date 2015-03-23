/* File: array_of_strings1.c
   A two-dimensional array of char
*/

#include <stdio.h>

int main() {
   char months[][4] =
     {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
      "Aug", "Sep", "Oct", "Nov", "Dec" } ;

   int i ;

   printf("*** Original ***\n") ;
   for (i = 0 ; i < 12 ; i++) {
      printf("%s\n", months[i]) ;
   }

   months[0][1] = 'u' ;

   printf("\n*** Modified ***\n") ;
   for (i = 0 ; i < 12 ; i++) {
      printf("%s\n", months[i]) ;
   }

   return 0 ;
}
