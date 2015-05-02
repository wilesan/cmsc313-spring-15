/*
 * main8.c
 *
 *  Created on: Apr 11, 2015
 *      Author: acw3f
 */

#include <stdio.h>
#include <unistd.h>

#include "rot13_dev.h"

struct rot13_dev
{
    union
    {
        unsigned int flags;
        struct
        {
            unsigned int input_ready: 1;
            unsigned int output_available:1;
            unsigned int interrupt_enable:1;
            unsigned int interrupt_ack:1;
        };
    };
    unsigned int in;
    unsigned int out;
};

struct interrupt_info
{
    struct rot13_dev *dev;
    char output_buffer[80];
    unsigned int output_buffer_len;
};

void interrupt(void *data)
{
    struct interrupt_info *info = (struct interrupt_info *)data;
    info->output_buffer[info->output_buffer_len++] = info->dev->out;
    info->dev->output_available = 0;
    info->dev->interrupt_ack = 0;
}

int main()
{
    char buffer[80];
    int ret, i;
    struct interrupt_info info = {0};
    info.dev = (struct rot13_dev *) init_rot13_dev(interrupt, &info);

    info.dev->interrupt_enable = 1;

    for (;;)
    {
        printf("Input to ROT13 (ENTER to exit)\n");
        ret = read(0, buffer, sizeof(buffer) - 1);
        if (buffer[0] == '\n')
        {
            return 0;
        }
        for (i = 0; i < ret; i++)
        {
            while(info.dev->input_ready == 1);
            info.dev->in = buffer[i];
            info.dev->input_ready = 1;
        }

        while(info.output_buffer_len < ret)
        {
            usleep(100);
        }

        printf("ROT13 String: ");
        fflush(stdout);
        write(1, info.output_buffer, info.output_buffer_len);
        printf("\n");
        info.output_buffer_len = 0;
    }

    return 0;
}


