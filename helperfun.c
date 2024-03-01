#include "main.h"

/**
 * our_putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int our_putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * our_strlen - calculates the length of a string
 * @str: input string
 *
 * Return: length of the string
 */
size_t our_strlen(const char *str)
{
	const char *pointer = str;

	while (*pointer != '\0')
	{
		pointer++;
	}
	return (pointer - str);
}

/**
 * our_strcmp - compares two strings
 * @str1: pointer to first string
 * @str2: pointer to second string
 *
 * Return: 0 if the strings are equal,
 * negative value if str1 < str2, positive value if str1 > str2
 */
int our_strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * our_strcpy - copies the contents of one string to another
 * including the null terminator
 * @dest: destination string
 * @src: source string
 *
 * Return: nothing
 */
void our_strcpy(char *dest, const char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

/**
 * our_atoi - converts a string into an integer
 * @str: string to convert
 *
 * Return: the converted integer
 */
int our_atoi(const char *str)
{
	int i = 0;
	int product = 0;
	int is_pos_or_neg = 1;

	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		is_pos_or_neg = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		product = product * 10 + (str[i] - '0');
		i++;
	}
	return (is_pos_or_neg * product);
}

