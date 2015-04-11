/*
 * main5.c
 *
 *  Created on: Mar 25, 2015
 *      Author: acw3f
 */

#include <stdio.h>
#include <string.h>
#include "book_info_heap.h"

typedef struct
{
    char title[50];
    char author[40];
    unsigned int year_published;
} my_book_info;

int score = 100;
int deducted_points_for_non_null = 0;

book_info *get_new_book_info(char *title, char *author, unsigned int year_published)
{
    book_info *info = new_book_info();
    if (info == NULL)
    {
        return NULL;
    }
    if ((deducted_points_for_non_null == 0) && (info->title[0] != 0 || info->author[0] != 0))
    {
        printf("Got book_info w/o clean title or author - -5\n");
        deducted_points_for_non_null = 1;
        score -= 5;
    }
    strncpy(info->title, title, sizeof(info->title) - 1);
    strncpy(info->author, author, sizeof(info->author) - 1);
    info->year_published = year_published;
    return info;
}

void print_info(const book_info *info)
{
    printf("Book Title: %s\n", info->title);
    printf("Book Author: %s\n", info->author);
    printf("Book Year Published: %u\n", info->year_published);
}

int main()
{
    book_info *info[20] = { NULL }, *info1;

    init_heap();

    printf("The following should show 20 available entries (all entries have year_published != 0) - deduct 3 points if it does not\n");
    dump_heap();

    info[0] = get_new_book_info("Rant: The Oral Biography of Buster Casey", "Chuck Palahniuk", 2008);
    del_book_info(info[0]);
    info[0] = get_new_book_info("Less Than Zero", "Bret Easton Ellis", 1985);

    info[1] = get_new_book_info("What If: Serious Scientific Answers to Absurd Hypothetical Questions", "Randall Monroe", 2014);

    info[2] = get_new_book_info("Ender\'s Game", "Orson Scott Card", 1985);

    del_book_info(info[1]);

    info[1] = new_book_info();
    if (info[1] == NULL)
    {
        printf("Got new_book_info() == NULL when should have been correct, -5\n");
        score -= 5;
    }
    else
    {
        memset(info[1]->author, 0, sizeof(info[1]->author));
        memset(info[1]->title, 0, sizeof(info[1]->title));
        info[1]->year_published = 0;
    }
    int i;
    if (sizeof(book_info) != sizeof(my_book_info))
    {
        printf("sizeof(book_info) == %d, not %d as it should - -5\n", sizeof(book_info), sizeof(my_book_info));
        score -= 5;
    }

    int j, set_error = 0;
    for (i = 3; i < 20; i++)
    {
        info[i] = new_book_info();
        if (info[i] == NULL)
        {
            printf("Got new_book_info() == NULL when should have been correct, -5\n");
            score -= 5;
            break;
        }
        memset(info[i]->author, 0, sizeof(info[i]->author));
        memset(info[i]->title, 0, sizeof(info[i]->title));
        info[i]->year_published = 0;
        for (j = 0; j < i; j++)
        {
            if (info[i] == info[j])
            {
                printf("%dth book_info is the same as %dth book_info - %p\n", i, j, info[i]);
                set_error = 1;
            }
        }
    }
    if (set_error)
    {
        printf("Allocator returns same pointer for multiple allocations - -5\n");
        score -= 5;
    }
    set_error = 0;
    printf("The following should show 0 free entries (all entries have year_published == 0, except indexes 0 & 2, which should both contain 1985) - deduct 3 points if it does not\n");
    dump_heap();

    book_info *last_info = info[19];

    book_info *next_info = new_book_info();
    if (next_info != NULL)
    {
        printf("Could allocate at least 21 entries - -5\n");
        score -= 5;
        del_book_info(next_info);
        next_info = NULL;
    }

    /* Free all entries */
    for (i = 19; i >= 0; i--)
    {
        if (info[i])
        {
            del_book_info(info[i]);
            info[i] = NULL;
        }
    }

    printf("The following should show 20 free entries (all entries have year_published != 0) - deduct 3 points if it does not\n");
    dump_heap();

    /* Allocate all entries */
    for (i = 0; i < 20; i++)
    {
        info[i] = new_book_info();
        if (info[i] == NULL)
        {
            printf("Got new_book_info() == NULL when should have been correct, -5\n");
            score -= 5;
            break;
        }
    }

    next_info = new_book_info();
    if (next_info != NULL)
    {
        printf("Could allocate at least 21 entries - -5\n");
        score -= 5;
        del_book_info(next_info);
        next_info = NULL;
    }

    /* Delete every other entry */
    for (i = 0; i < 20; i+= 2)
    {
        if (info[i])
        {
            del_book_info(info[i]);
            info[i] = NULL;
        }
    }

    /* Now, reallocate them */
    for (i = 0; i < 20; i+= 2)
    {
        info[i] = new_book_info();
        if (info[i] == NULL)
        {
            printf("Got new_book_info() == NULL when should have been correct, -5\n");
            score -= 5;
            break;
        }
    }

    next_info = new_book_info();
    if (next_info != NULL)
    {
        printf("Could allocate at least 21 entries - -5\n");
        score -= 5;
        del_book_info(next_info);
        next_info = NULL;
    }

    printf("If you don't see another line with \"Final Score\" at the beginning, the Final Score is: %d\n", score);
    del_book_info(NULL);
    score -= 5;
    printf("Failed to exit the program with a bad pointer in del_book_info() - -5\n");
    printf("Final Score: %d\n", score);
    return 0;
}
