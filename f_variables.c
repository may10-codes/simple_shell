#include "main.h"

/**
*get_variables-gets the variables
*@tokens: array of tokens
*@exit_status: exit status
*Return: nothing
*/
void get_variables(char **tokens, int *exit_status)
{
int i;
for (i = 0; tokens[i] != NULL; i++)
{
if (our_strcmp(tokens[i], "$?") == 0)
{
free(tokens[i]);
tokens[i] = malloc(12);
our_printf(tokens[i], 12, "%d", *exit_status);
}
else if (our_strcmp(tokens[i], "$$") == 0)
{
free(tokens[i]);
tokens[i] = malloc(12);
our_printf(tokens[i], 12, "%d", getpid());
}
}
}

