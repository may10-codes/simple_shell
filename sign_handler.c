#include "main.h"

/**
 * sigint_handler - handles SIGINT signal
 * @sig: the exact signal number (unused)
 *
 * Description: Handles the SIGINT signal (Ctrl+C) by freeing global_buffer
 *              if it's not NULL, printing a newline character, and exiting
 *              with status 130.
 */
void sigint_handler(int sig)
{
	char *global_buffer = NULL;

	(void)sig; /* Unused parameter */

	/* Free global_buffer if not NULL */
	if (global_buffer != NULL)
	{
		free(global_buffer);
		global_buffer = NULL;
	}

	/* Print newline character */
	our_putchar('\n');

	/* Exit with status 130 */
	exit(130);
}

/**
 * flush_buffer - checks whether buffer contains spaces or is empty
 *
 * Return: 0 if buffer contains non-space characters, 1 if buffer is empty
 */
int flush_buffer(void)
{
	char *global_buffer = NULL;
	int i = 0;

	/* Iterate through global_buffer */
	for (; global_buffer[i]; i++)
	{
		/* If non-space character is found, return 0 */
		if (global_buffer[i] != ' ')
			return (0);
	}

	/* Free global_buffer */
	free(global_buffer);

	/* Return 1 if buffer is empty */
	return (1);
}

