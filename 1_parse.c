#include "main.h"

/**
 * parse_arguments - Parses command line arguments
 * @input: The input string containing the command and arguments
 * @args: Array to store the parsed arguments
 *
 * Return: The number of arguments parsed
 *
 * Description: This function tokenizes the input string using space
 *              as the delimiter and stores the tokens into the args array.
 *              It returns the total number of arguments parsed.
 */
int parse_arguments(char *input, char **args)
{
	int count = 0;
	char *token = strtok(input, " ");

	/* Tokenize the input string */
	while (token != NULL)
	{
		/* Copy the token into the args array */
		args[count] = our_strdup(token);
		count++;
		token = strtok(NULL, " ");
	}
	/* Set the last element of args array to NULL */
	args[count] = NULL;

	return (count);
}

