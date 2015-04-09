/*
 * sorter.c
 *
 *  Created on: Apr 2, 2015
 *      Author: acw3f
 */

/* Prototypes for external functions */
int read(int fd, void *buffer, unsigned int size);
int write(int fd, const void *buffer, unsigned int size);
int strcmp(const char *buf1, const char *buf2);

/* Some constants */
#define ARRAY_ELEMENTS      20
#define STRING_SIZE         50
#define STDOUT              0
#define STDIN               1

/* Prints a NULL-terminated string to STDOUT */
void print(const char *buf)
{
    while(*buf)
    {
        write(STDOUT, buf, 1);
        buf++;
    }
}

int main()
{
    char strings[ARRAY_ELEMENTS][STRING_SIZE];
    char *sorted_strings[ARRAY_ELEMENTS];

    int n, c, d, len;
    char *swap;
    char message1[] = "Enter a string (press ENTER to finish and sort)\n";

    n = 0;

    /* Read in a bunch of strings */
    do
    {
        write(STDOUT, message1, sizeof(message1) - 1);
        len = read(STDIN, strings[n], sizeof(strings[n]));
        /* Subtract 1 to remove the \n from the end */
        strings[n][len - 1] = 0;
        sorted_strings[n] = strings[n];
        n++;
    } while((n < ARRAY_ELEMENTS) && (strings[n-1][0] != 0));

    /* Bubble-sort the strings read in ascending order */
    for (c = 0 ; c < ( n - 1 ); c++)
    {
        for (d = 0 ; d < n - c - 1; d++)
        {
            if (strcmp(sorted_strings[d], sorted_strings[d+1]) > 0)
            {
                swap                = sorted_strings[d];
                sorted_strings[d]   = sorted_strings[d+1];
                sorted_strings[d+1] = swap;
            }
        }
    }

    /* Display the strings in ascending order */
    char message2[] = "Sorted list in ascending order:\n";
    write(STDOUT, message2, sizeof(message2) - 1);

    for ( c = 0 ; c < n ; c++ )
    {
        print(sorted_strings[c]);
        print("\n");
    }

    return 1;
}

