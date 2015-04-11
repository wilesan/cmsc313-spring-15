/*
 * main5.c
 *
 *  Created on: Mar 25, 2015
 *      Author: acw3f
 */

#include <stdio.h>
#include <string.h>
#include "book_info_heap_ec.h"

int score = 10;

int main()
{
    book_info *info1, *info2;

    init_heap();

    info1 = new_book_info_array(20);
    if (info1 == NULL)
    {
        printf("Failed to allocate 20 element array from empty array - -2\n");
        score -= 2;
    }
    //dump_heap();
    info2 = new_book_info();
    if (info2 != NULL)
    {
        printf("Failed to get array & regular alloactor to work properly - -2\n");
        dump_heap();
        score -= 2;
        del_book_info(info2);
        info2 = NULL;
    }
    if (info1)
    {
        del_book_info_array(info1);
        info1 = NULL;
    }
    //dump_heap();

    info1 = new_book_info_array(12);
    info2 = new_book_info_array(12);

    if (info2 != NULL)
    {
        printf("Failed to account for multiple new_book_info_arrays() - -2\n");
        score -= 2;
        del_book_info(info2);
    }
    del_book_info_array(info1);

    info2 = new_book_info();
    info1 = new_book_info(9);
    if (info1 == NULL)
    {
        printf("Failed to get array after regular allocator - -2\n");
        score -= 2;
    }
    else
    {
        del_book_info_array(info1);
    }
    del_book_info(info2);
    book_info *info_arr[10];
    int i;
    //dump_heap();
    for (i = 0; i < 10; i++)
    {
        info_arr[i] = new_book_info();
        if (info_arr[i] == NULL)
        {
            printf("Could not allocate regular book_info - -4\n");
            score -= 4;
            goto done;
        }
    }
    info1 = new_book_info(10);
    if (info1 == NULL)
    {
        printf("Could not allocate book_info after allocating 10 regular books, -2\n");
        score -= 2;
    }
    else
    {
        del_book_info_array(info1);
    }
done:
    printf("Final score: %d\n", score < 0 ? 0 : score);
}
