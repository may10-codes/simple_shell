#include "main.h"

/**
 * print_hsh_error - Print error message with ./hsh prefix.
 * @message: The error message to display.
 *@shell_name: shell name
 */
void print_hsh_error(const char *message, const char *shell_name)
{
	char error_statement[100];

	our_strcpy(error_statement, shell_name);
	our_strcat(error_statement, ": ");
	our_strcat(error_statement, message);
	write(STDERR_FILENO, error_statement, our_strlen(error_statement));
}
