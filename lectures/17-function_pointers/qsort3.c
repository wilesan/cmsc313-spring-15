/* File: qsort3.c

   Demonstrating use of callback functions in qsort().
   This time we sort an array of pointers.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int (* COMP_FUNC_PTR) (const void *, const void *) ;

typedef struct {
    char   realname[32] ;
    char   nickname[16] ;
    char   alignment[20] ;
    char   role[20] ;
    int    points ;
    int    level ;
    
} Player ;


Player records[25] = {
   {"Allen, Kevin P.", "kallen1", "neutral good", "Paladin", 6721, 6},
   {"Baker, Matthew R.", "mbaker5", "true neutral", "Thief", 4313, 4},
   {"Chandlee, Richard C.", "rchand1", "lawful evil", "Ranger", 3196, 3},
   {"Cloud, Clinton E.", "ccloud2", "chaotic good", "Magician", 9583, 9},
   {"Cobb, Milton T.", "cobb", "lawful neutral", "Fighter", 9169, 9},
   {"Frankle, Alan E.", "frankle1", "chaotic good", "Fighter", 8924, 9},
   {"Fu, David E.", "dfu1", "chaotic good", "Ranger", 10011, 12},
   {"Helton, Robert L.", "helton1", "true neutral", "Paladin", 3034, 3},
   {"Joshua, Aimee", "ajoshu1", "chaotic evil", "Thief", 3733, 4},
   {"Macdonald, Matthew S.", "matmacd1", "chaotic good", "Fighter", 3797, 5},
   {"Mcelvaney, Erin L.", "emcelv1", "lawful neutral", "Cleric", 9896, 11},
   {"Mitchell, Susan M.", "smitchel", "neutral good", "Fighter", 9740, 10},
   {"Mittal, Sandeep K.", "smitta1", "chaotic good", "Cleric", 2706, 2},
   {"Moore, Brian A.", "bmoore1", "lawful evil", "Ranger", 4016, 4},
   {"Napier, Matthew A.", "mnapie1", "true neutral", "Magician", 4539, 5},
   {"Nguyen, Michael D.", "mnguyen1", "chaotic good", "Ranger", 9490, 9},
   {"Orticke, Alecia G.", "aortic1", "chaotic good", "Cleric", 2048, 4},
   {"Palewicz, David E.", "dpalew1", "chaotic good", "Thief", 765, 3},
   {"Raby, Adam M.", "araby1", "lawful neutral", "Magician", 8814, 9},
   {"Roberts, Eric J.", "erober3", "neutral good", "Fighter", 7765, 7},
   {"Rusinko, Nicholas D.", "nrusin1", "lawful good", "Thief", 5095, 5},
   {"Seo, Maximilian", "mseo1", "chaotic evil", "Ranger", 3205, 3},
   {"Shenvi, Shilpa P.", "shenvi1", "neutral good", "Thief", 9573, 10},
   {"Szrom, Michelle L.", "mszrom1", "chaotic good", "Cleric", 9660, 9},
   {"Tuveson, Eric A.", "etuves1", "chaotic evil", "Thief", 9245, 7}
} ;



void PrintPlayer(Player *p) {

   printf("%32s (%16s)  %20s  %20s(%3d)  %10d\n",
      p->realname, p->nickname, p->alignment, p->role, p->level,
      p->points) ;
}


int byPoints(Player **p1, Player **p2) {
   return (*p1)->points - (*p2)->points ;
}

int byNickname(Player **p1, Player **p2) {
   return strcmp((*p1)->nickname, (*p2)->nickname) ;
}

int byAlignment(Player **p1, Player **p2) {
   return strcmp((*p1)->alignment, (*p2)->alignment) ;
}

int main () {

   int i ; 
   Player *rec_ptrs[25] ;

   for (i = 0 ; i < 25 ; i++) {
      rec_ptrs[i] = &records[i] ;
   }


   printf("Original list:\n") ;
   for (i = 0 ; i < 25 ; i++) {
      PrintPlayer(rec_ptrs[i]) ;
   }


   qsort(rec_ptrs, 25, sizeof(Player *), (COMP_FUNC_PTR) &byPoints) ;

   printf("\n\nSorted by points:\n") ;
   for (i = 0 ; i < 25 ; i++) {
      PrintPlayer(rec_ptrs[i]) ;
   }


   qsort(rec_ptrs, 25, sizeof(Player *), (COMP_FUNC_PTR) &byNickname) ;

   printf("\n\nSorted by nickname:\n") ;
   for (i = 0 ; i < 25 ; i++) {
      PrintPlayer(rec_ptrs[i]) ;
   }


   qsort(rec_ptrs, 25, sizeof(Player *), (COMP_FUNC_PTR) &byAlignment) ;

   printf("\n\nSorted by alignment:\n") ;
   for (i = 0 ; i < 25 ; i++) {
      PrintPlayer(rec_ptrs[i]) ;
   }

   printf("\n\nOriginal list (again):\n") ;
   for (i = 0 ; i < 25 ; i++) {
      PrintPlayer(&records[i]) ;
   }

   return 0 ;
}
