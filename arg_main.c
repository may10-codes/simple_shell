#include "main.h"

#define BUFFER_SIZE 1024

/**
 * shell_main - Entry point
 *
 * Return: 0 on success
 */
int shell_main(void)
{
	char input[BUFFER_SIZE];
	char *command;
	char *args[BUFFER_SIZE];
	int num_args;
	int i;
	ssize_t bytes_read;
	size_t bufsize = BUFFER_SIZE;

	write(STDOUT_FILENO, "#cisfun$", 8);

	while ((bytes_read = read(STDIN_FILENO, input, bufsize)) > 0)
	{
		if (input[bytes_read - 1] == '\n')
			input[bytes_read - 1] = '\0';
		num_args = parse_arguments(input, args);
		command = args[0];

		execute_command(command, args);

		for (i = 0; i <= num_args; i++)
		{
			free(args[i]);
		}
		write(STDOUT_FILENO, "#cisfun:) ", 10);
	}

	return (EXIT_SUCCESS);
}

