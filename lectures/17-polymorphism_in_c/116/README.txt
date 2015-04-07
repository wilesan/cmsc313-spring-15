Directory: ll6

In this version nodes in linked lists have a pointer to an array of
function pointers. Currently, the array has two functions: one to print
a node and one to deallocate a node. More functions can be added.


ll.c: Note new syntax to invoke a function from an array of function
pointers. The DEL_VF (delete virtual function) is called from LL_Delete
and LL_Empty.


main12.c: linked list of int

main13.c: linked list of double

main14.c: linked list of int and double in the same list.

main15.c: linked list of string. Check that strings are deallocated.

main16.c: linked list of string and show that we can modify the string.
   Uses #ifndef around debugging messages. To compile without debugging
   messages:

      gcc -Wall -c -DNDEBUG main16.c
