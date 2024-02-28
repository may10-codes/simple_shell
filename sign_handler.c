#include "main.h"
#include <stdio.h>

/**
 * our_strlen - calculates the length of a string
 * @src: the string whose length is to be calculated
 *
 * Return: the length of the string
 */
size_t our_strlen(const char *src)
{
        size_t len = 0;

        while (src[len])
                len++;
        return (len);
}

/**
 * signal_handler - handles signals, specifically for CTRL+C
 * @sign: signal number
 *
 * This function is invoked when a signal is caught, such as CTRL+C.
 * It writes a prompt to stdout and flushes it.
 */
void signal_handler(int sign)
{
        char *prompt = "\n$ ";

        (void)sign; /* Ignoring the signal argument */
        write(1, prompt, our_strlen(prompt)); /* Writing prompt to stdout */
        fflush(stdout); /* Flushing stdout */
}

