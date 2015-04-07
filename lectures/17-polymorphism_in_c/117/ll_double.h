#ifndef _LL_DOUBLE_H
#define _LL_DOUBLE_H

#include "ll.h"

typedef struct double_node {
   one_ftype *vfunc ;
   struct double_node *next ;
   double data ;
} double_node ;


double_node *new_double_node (double data) ;

void del_double_node(double_node *ptr) ;

void print_double_node(double_node *ptr) ;

extern one_ftype Double_VFuncs[] ;


#endif
