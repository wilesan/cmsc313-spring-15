/* File: array_of_strings2.c
   A two-dimensional array of char.  Using a typedef.
*/

#include <stdio.h>

typedef char Acronym[4] ;

int main() {
   Acronym months[] =
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
