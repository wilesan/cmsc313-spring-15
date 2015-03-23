/* File: array_of_strings3.c
   
   A one-dimensional array of char pointers.
*/


#include <stdio.h>

int main() {

   char *name[] = { "Bobby", "Jim", "Harold" } ;

   printf("Three amigos: %s, %s and %s.\n", 
      name[0], name[1], name[2]) ;

   // can point to another name this way.
   name[2] = "Jimbo" ;

   printf("Three good ole boys: %s, %s and %s.\n", 
      name[0], name[1], name[2]) ;

   return 0 ;
}
