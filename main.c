#include "main.h"

/**
 * main - Main entry point for the program
 * @argc: Argument count for the main function
 * @argv: Array of argument values
 *
 * Return: Always returns 0 indicating success
 */
int main(int argc, char *argv[])
{
    /* Suppress unused parameter warnings */
    (void)argc;
    (void)argv;

    /* Write prompt to stdout */
    write(STDOUT_FILENO, "magic_simpleshell# ", 18);


    return (0);
}

