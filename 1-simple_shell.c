#include "main.h"

/**
 * display_prompt - Functions to allow user to see prompt
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "#cisfun$", 8);
}

#include "main.h"

/**
 * execute_input - Functions to execute commands.
 * @input: The command to be executed.
 *
 * Return: The result after execution of the command.
 */
void execute_input(char *input)
{
	int argc = 0;
	char *argv[MAX_ARGS + 1];
	char *token = strtok(input, " \t\n");

	while (token != NULL && argc < MAX_ARGS)
	{
		argv[argc] = token;
		argc++;
		token = strtok(NULL, " \t\n");
	}
	argv[argc] = NULL;

	if (argc == 0)
	{
		return;
	}
	else
	{
		execute_command_or_process(argc, argv);
	}
}

/**
 * execute_command_or_process - Execute the appropriate command or process.
 * @argc: Number of arguments in the command.
 * @argv: Array of arguments in the command.
 */
void execute_command_or_process(int argc, char *argv[])
{
	if (our_strcmp(argv[0], "exit") == 0)
	{
		if (argc > 1)
		{
			int exit_shell = our_atoi(argv[1]);
			exit(exit_shell);
		}
		else
		{
			exit(EXIT_SUCCESS);
		}
	}
	else if (our_strcmp(argv[0], "env") == 0)
	{
		our_env();
	}
	else
	{
		handle_other_commands(argc, argv);
	}
}

/**
 * handle_other_commands - Handle non-built-in commands using PATH.
 * @argc: Number of arguments in the command.
 * @argv: Array of arguments in the command.
 */
void handle_other_commands(int argc __attribute__((unused)), char *argv[])
{
	pid_t pid;
	int path_result = path(&argv[0]);

	if (path_result == 0)
	{
		handle_error("command not found", argv[0]);
	}
	else if (path_result == -1)
	{
		handle_error("permission denied", argv[0]);
	}
	else
	{
		pid = fork();
		if (pid < 0)
		{
			perror("fork failed");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execute_command(argv[0], argv);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
		}
	}
}

/**
 * read_execute_loop - read a line from the standard input
 * Return: pointer that points to a str with the line content
 */
void read_execute_loop(void)
{
	char input[MAX_INPUT];
	int read_status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();
		read_status = read(STDIN_FILENO, input, MAX_INPUT);
		if (read_status == -1)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}

		if (read_status == 0)
		{
			exit(EXIT_SUCCESS);
		}

		if (input[read_status - 1] == '\n')
			input[read_status - 1] = '\0';

		get_comments(input);
		if (our_strcmp(input, "") == 0)
		{
			continue;
		}
		execute_input(input);
	}
}

