/*
 * main5.c
 *
 *  Created on: Mar 25, 2015
 *      Author: acw3f
 */

#include <stdio.h>
#include <string.h>
#include "book_info_heap.h"

book_info *get_new_book_info(char *title, char *author, unsigned int year_published)
{
    book_info *info = new_book_info();
    if (info == NULL)
    {
        return NULL;
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
    book_info *info1, *info2, *info3;

    init_heap();

    info1 = get_new_book_info("Rant: The Oral Biography of Buster Casey", "Chuck Palahniuk", 2008);

    print_info(info1);

    dump_heap();

    del_book_info(info1);

    info1 = get_new_book_info("Less Than Zero", "Bret Easton Ellis", 1985);

    info2 = get_new_book_info("What If: Serious Scientific Answers to Absurd Hypothetical Questions", "Randall Monroe", 2014);

    info3 = get_new_book_info("Ender\'s Game", "Orson Scott Card", 1985);

    dump_heap();

    del_book_info(info2);

    dump_heap();
    return 0;
}
