/* File: doarray.c
*/

typedef int (* INT_INT_FPTR) (int) ;

void do_array(int A[], int size, INT_INT_FPTR fptr) {
   int i ;

   for ( i = 0 ; i < size ; i++) {
      A[i] = (* fptr) (A[i]) ;
   }
}

