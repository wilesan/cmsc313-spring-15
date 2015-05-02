/*
 * main8.c
 *
 *  Created on: Apr 11, 2015
 *      Author: acw3f
 */

#include <stdio.h>
#include <unistd.h>

#include "rot13_dev.h"

#define INPUT_READY_BIT         0
#define OUTPUT_AVAILABLE_BIT    1
#define INTERRUPT_ENABLE_BIT    2
#define INTERRUPT_ACK_BIT       3

struct rot13_dev
{
    unsigned int flags;
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
    /* Get Output from hardware into output buffer */
    info->output_buffer[info->output_buffer_len++] = info->dev->out;
    /* Clear the Interrupt Ack and Output Available bits in flags */
    info->dev->flags &= ~((1 << OUTPUT_AVAILABLE_BIT) | (1 << INTERRUPT_ACK_BIT));
}

int main()
{
    char buffer[80];
    int ret, i;
    struct interrupt_info info = {0};
    info.dev = (struct rot13_dev *) init_rot13_dev(interrupt, &info);

    /* Enable interrupt */
    info.dev->flags |= (1 << INTERRUPT_ENABLE_BIT);

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
            /* Wait for Input Ready bit to become 0 */
            while(info.dev->flags & (1 << INPUT_READY_BIT));
            /* Put one byte from input buffer into hardware input register */
            info.dev->in = buffer[i];
            /* Set the Input Ready bit to 1 */
            info.dev->flags |= 1;
        }

        /* Wait for all output to complete processing in ISR */
        while(info.output_buffer_len < ret)
        {
            usleep(100);
        }

        /* Print output buffer */
        printf("ROT13 String: ");
        fflush(stdout);
        write(1, info.output_buffer, info.output_buffer_len);
        printf("\n");
        info.output_buffer_len = 0;
    }

    return 0;
}


