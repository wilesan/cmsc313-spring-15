/*
 * rot13_dev.c
 *
 *  Created on: Apr 11, 2015
 *      Author: acw3f
 */

#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "rot13_dev.h"

struct rot13_dev
{
    union
    {
        unsigned int flags;
        struct
        {
            unsigned int in_fifo_ready: 1;
            unsigned int output_available:1;
            unsigned int interrupt_enable:1;
            unsigned int interrupt_ack:1;
        };
    };
    unsigned int in;
    unsigned int out;
};

#if !defined(FALSE)
#define FALSE   0
#endif
#if !defined(TRUE)
#define TRUE    (!FALSE)
#endif
struct rot13_dev dev;
void (*callback)(void *) = NULL;
void *callback_data;
pthread_t thread;
pthread_t kill_thread;

void *rot13_thread_fn(void *ignore)
{
    (void)ignore;

    for (;;)
    {
        usleep(100);
        if (dev.in_fifo_ready && (dev.output_available == 0))
        {
            if (isalnum(dev.in))
            {
                dev.out = dev.in + 13;
            }
            else
            {
                dev.out = dev.in;
            }
            dev.output_available = 1;
            dev.in_fifo_ready = 0;
            if (dev.interrupt_enable && (dev.interrupt_ack == 0))
            {
                dev.interrupt_ack = 1;
                pthread_kill(kill_thread, SIGUSR1);
            }
        }
    }
    return NULL;
}

void sighandler(int sig)
{
    (void)sig;
    if (callback)
    {
        callback(callback_data);
    }
}

void *init_rot13_dev(void (*interrupt_fn)(void *data), void *data)
{
    if (interrupt_fn == NULL)
    {
        return NULL;
    }
    if (callback != NULL)
    {
        return &dev;
    }
    memset(&dev, 0, sizeof(dev));
    pthread_create(&thread, NULL, rot13_thread_fn, NULL);
    callback = interrupt_fn;
    callback_data = data;
    kill_thread = pthread_self();
    if (signal(SIGUSR1, sighandler) == SIG_ERR)
    {
        perror("init_rot13");
        exit(1);
    }
    return &dev;
}
