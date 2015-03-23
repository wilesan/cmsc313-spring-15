/* File: array_of_strings5.c
   
   A one-dimensional array of char pointers.
*/

#include <stdio.h>

int main() {

   char *name[] = { "Bobby", "Jim", "Harold" } ;

   // An honest to goodness array of char
   char jimbo[] = "Jimbo" ;  

   printf("Three amigos: %s, %s and %s.\n", 
      name[0], name[1], name[2]) ;

   // point to array of char named jimbo
   name[2] = jimbo ;

   printf("Three good ole boys: %s, %s and %s.\n", 
      name[0], name[1], name[2]) ;

   printf("Last 2 letters of \"Jimbo\" are '%c' and '%c'\n", 
      name[2][3], name[2][4] ) ;

   // Can use two-dimensional array syntax to rename Jimbo to Jimmy
   name[2][3] = 'm' ;
   name[2][4] = 'y' ;

   printf("Jimbo changed his name to %s\n", name[2]) ;
   printf("Jimbo's new name is %s\n", jimbo) ;

   return 0 ;
}
