/* File: main15.c

   Using generic functions in ll.c to implement
   a linked list of string.

   new_str_node() in this version makes a copy of the string
   given in its argument.

   This version has a virtual function table.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"

typedef struct str_node {
   one_ftype *vfunc ;
   struct str_node *next ;
   char *data ;
} str_node ;


void print_str_node(str_node *ptr) {
   printf("%s ", ptr->data) ;   
   return ;
}


void del_str_node(str_node *ptr) {
   fprintf (stderr, "Deleting memory for string: %s\n", ptr->data) ;
   free(ptr->data) ;
   free(ptr) ;
   return ;
}


one_ftype Str_VFuncs[2] = { 
   (one_ftype) &print_str_node, 
   (one_ftype) &del_str_node 
} ;


str_node *new_str_node (const char *str) {
   str_node *ptr ;

   ptr = malloc(sizeof(*ptr)) ;
   if (ptr == NULL) {
      fprintf(stderr, "Could not malloc() in new_str_node()!\n") ;
      exit(1) ;
   }
   ptr->vfunc = Str_VFuncs ;
   ptr->data = strdup(str) ;    // copy of string!
   if (ptr->data == NULL) {
      fprintf(stderr, "Could not malloc() in new_str_node()!\n") ;
      exit(1) ;
   }
   ptr->next = NULL ;
   return ptr ;
}




int main() {
   base_node *list1 ;
   str_node *ptr ;

   printf("New list1: ") ;
   list1 = LL_New() ;
   LL_Insert(list1, new_str_node("Hello")) ;
   LL_Insert(list1, new_str_node("World. ")) ;
   LL_Insert(list1, new_str_node("My name is")) ;
   LL_Insert(list1, new_str_node("Zaphod Beeblebrox. ")) ;
   LL_Insert(list1, new_str_node("I stole the")) ;
   LL_Insert(list1, new_str_node("Heart of Gold. ")) ;
   LL_Insert(list1, new_str_node("Good-bye!")) ;

   LL_Print(list1) ;

   printf("Remove 1 node: ") ;
   LL_Delete(list1) ;
   LL_Print(list1) ;


   printf("First item: ") ;
   ptr = (str_node *) LL_First(list1) ;
   printf("%s ", ptr->data) ;
   printf("\n") ;
   
   printf("Reverse list: ") ;
   base_node *temp_list = LL_New() ;
   while( ( ptr = (str_node *) LL_Extract(list1) )) {
      LL_Insert(temp_list, ptr) ;
   }
   LL_Destroy(list1) ;
   list1 = temp_list ;   //shallow copy
   temp_list = NULL ;
   LL_Print(list1) ;

   LL_Destroy(list1) ;
   return 0 ;
}
