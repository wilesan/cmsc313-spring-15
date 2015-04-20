/*
 * main6_ta.c
 *
 *  Created on: Apr 2, 2015
 *      Author: acw3f
 */

#include <stdio.h>
#include "buf_desc.h"

typedef struct my_buf_desc
{
    void *buffer;
    unsigned int len;
    struct buf_desc *next;
} my_buf_desc;

int score = 100;

int main()
{
    int i;
    init_buf_desc();

    buf_desc *buf = new_buf_desc();
    buf->buffer = "1234";
    buf->len = 4;

    buf_desc *buf2 = new_buf_desc();
    buf2->buffer = "5678";
    buf2->len = 4;

    buf->next = buf2;

    hexdump_buf_desc(buf);

    printf("CHECK OUTPUT: The next dump should show exactly 8 available and a total of 10 buffers - manually subtract 3 if it does not\n");
    dump_buf_desc();

    del_buf_desc(buf);

    printf("CHECK OUTPUT: The next dump should show exactly 10 available and a total of 10 buffers - manually subtract 5 if it does not\n");
    dump_buf_desc();

    buf = new_buf_desc();
    buf2 = buf;

    for (i = 0; i < 10; i++)
    {
        buf2->next = new_buf_desc();
        buf2 = buf2->next;
    }

    printf("CHECK OUTPUT: The next dump should show exactly 9 available buffers and a total of 20 buffers - manually subtract 5 if it does not\n");
    dump_buf_desc();

    clean_buf_desc();

    printf("CHECK OUTPUT: The next dump should show exactly 9 available buffers and a total of 20 buffers - manually subtract 5 if it does not\n");
    dump_buf_desc();


    buf2 = buf->next;
    buf->next = NULL;

    del_buf_desc(buf);
    buf = buf2->next;
    buf2->next = NULL;
    del_buf_desc(buf2);

    printf("CHECK OUTPUT: The next dump should show exactly 11 available buffers and a total of 20 buffers - manually subtract 5 if it does not\n");
    dump_buf_desc();

    clean_buf_desc();

    printf("CHECK OUTPUT: The next dump should show exactly 1 available buffers and a total of 10 buffers - manually subtract 5 if it does not\n");
    dump_buf_desc();

    del_buf_desc(buf);

    printf("CHECK OUTPUT: The next dump should show exactly 10 available buffers and a total of 10 buffers - manually subtract 5 if it does not\n");
    dump_buf_desc();

    if (sizeof(my_buf_desc) != sizeof(buf_desc))
    {
        printf("buf_desc length %d is not the correct length: %d - subtracting 5\n", sizeof(buf_desc), sizeof(my_buf_desc));
        score -= 5;
    }

    char buffer[20 * 4];
    for (i = 0; i < (20 * 4); i++)
    {
        buffer[i] = 'A' + (i & 0x7);
    }

    buf_desc *desc_array[20];
    int j, set_error = 0;
    for (i = 0; i < 20; i++)
    {
        desc_array[i] = new_buf_desc();
        if (i > 0)
        {
            desc_array[i-1]->next = desc_array[i];
        }

        if (desc_array[i] == NULL)
        {
            printf("Got new_buf_desc() == NULL when should have been correct, -5\n");
            score -= 5;
            break;
        }
        desc_array[i]->buffer = &buffer[i * 4];
        desc_array[i]->len = 4;

        for (j = 0; j < i; j++)
        {
            if (desc_array[j] == desc_array[i])
            {
                printf("%dth buf_desc is the same as %dth buf_desc - %p\n", i, j, desc_array[i]);
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

    buf = new_buf_desc();
    if (buf != NULL)
    {
        printf("Was allowed to allocate too many buffers - -5\n");
        score -= 5;
        del_buf_desc(buf);
    }

    printf("CHECK OUTPUT: The next dump should show exactly 10 hexdump'd rows of \"ABCDEFGH\" - manually subtract 10 if it does not\n");
    hexdump_buf_desc(desc_array[0]);

    printf("Remember to subtract anything listed preceded with \"CHECK OUTPUT\" above from this final score: %d\n", score);
    return 0;
}
