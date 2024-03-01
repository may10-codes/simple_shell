#include "main.h"

/**
 * int_to_str - converts int to str
 * @num: int
 * @str: str
 *
 * Description: Converts an integer to a string.
 *              The result is stored in the provided character array.
 */
void int_to_str(int num, char *str)
{
	char temp;
	int i;
	int len = 0;

	/* Convert integer to string */
	while (num > 0)
	{
		str[len++] = '0' + (num % 10);
		num /= 10;
	}

	/* Reverse the string */
	for (i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

/**
 * handle_error - handles errors
 * @error_msg: error message
 * @command: command
 *
 * Description: Prints an error message to stderr in a specific format
 *              and exits with failure status.
 */
void handle_error(const char *error_msg, char *command)
{
	char error_statement[100];
	char exit_status_str[10];
	int exit_status = errno, len = 0, i;

	/* Convert exit status to string */
	int_to_str(exit_status, exit_status_str);

	/* Construct error statement */
	error_statement[len++] = '.';
	error_statement[len++] = '/';
	error_statement[len++] = 'h';
	error_statement[len++] = 's';
	error_statement[len++] = 'h';
	error_statement[len++] = ':';
	error_statement[len++] = ' ';
	for (i = 0; exit_status_str[i] != '\0'; i++)
	{
		error_statement[len++] = exit_status_str[i];
	}
	error_statement[len++] = ':';
	error_statement[len++] = ' ';
	for (i = 0; command[i] != '\0'; i++)
	{
		error_statement[len++] = command[i];
	}
	error_statement[len++] = ':';
	error_statement[len++] = ' ';
	for (i = 0; error_msg[i] != '\0'; i++)
	{
		error_statement[len++] = error_msg[i];
	}
	error_statement[len++] = '\n';

	/* Print error statement to stderr */
	write(STDERR_FILENO, error_statement, len);

	/* Exit with failure status */
	exit(EXIT_FAILURE);
}

/**
 * execute_command - executes commands
 * @command: command
 * @args: arguments
 *
 * Description: Executes the provided command with the given arguments.
 *              If the command does not exist or has no execute permission,
 *              an error message is displayed.
 */
void execute_command(char *command, char **args)
{
	pid_t pid;
	int exit_status = 0;

	struct stat st;

	/* Check if command exists */
	if (stat(command, &st) == 0)
	{
		/* Check if command has execute permission */
		if (access(command, X_OK) == 0)
		{
			/* Get variables */
			get_variables(args, &exit_status);

			/* Fork process */
			pid = fork();

			if (pid < 0)
			{
				perror("fork failed");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0) /* Child process */
			{
				/* Execute command */
				if (execve(command, args, environ) == -1)
				{
					handle_error(strerror(errno), command);
				}
			}
			else /* Parent process */
			{
				wait(NULL);
			}
		}
		else /* No execute permission */
		{
			handle_error("permission denied", command);
		}
	}
	else /* Command not found */
	{
		handle_error("no such file or directory", command);
	}
}

