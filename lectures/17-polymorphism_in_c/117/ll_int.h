#ifndef _LL_INT_H
#define _LL_INT_H

#include "ll.h"

typedef struct int_node {
   one_ftype *vfunc ;
   struct int_node *next ;
   int data ;
} int_node ;


int_node *new_int_node (int data) ;

void del_int_node(int_node *ptr) ;

void print_int_node(int_node *ptr) ;

extern one_ftype Int_VFuncs[] ;

#endif
