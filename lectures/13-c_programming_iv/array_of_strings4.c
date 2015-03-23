/* File: array_of_strings4.c
    
   An array of char pointers.
*/

#include <stdio.h>

int main() {

   char *name[] = { "Bobby", "Jim", "Harold" } ;

   printf("Three amigos: %s, %s and %s.\n", 
      name[0], name[1], name[2]) ;

   // Can point to a different name this way
   name[2] = "Jimbo" ;

   printf("Three good ole boys: %s, %s and %s.\n", 
      name[0], name[1], name[2]) ;

   printf("Last 2 letters of \"Jimbo\" are '%c' and '%c'\n", 
      name[2][3], name[2][4] ) ;

   // Change "Jimbo" to "Jimmy"??
   // These two assignments cause segmentation faults
   name[2][3] = 'm' ;
   name[2][4] = 'y' ;

   return 0 ;
}
