#include "main.h"
#include <stdlib.h>

/**
 * our_strdup - Custom implementation of strdup function.
 * @s: The string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL if allocation fails.
 */
char *our_strdup(const char *s)
{
	size_t len = our_strlen(s) + 1;
	char *dup = malloc(len);

	if (dup != NULL)
	{
		our_strcpy(dup, s);
	}
	return (dup);
}

/**
 * our_strcat -attaches the contents of one string to the end
 * od another string including the terminating byte
 *@src: string to attach
 *@dest: string to attach to
 *Return: nothing
 */
void our_strcat(char *dest, const char *src)
{
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

/**
 *our_printf - function that mimics the standard printf
 *
 * @format: string
 * Return: integer value
 */
int our_printf(const char *format, ...)
{
	int i = 0, j = 0;
	char *str;
	va_list args;

	va_start(args, format);
	if (format[i] == '%' || (format[i] == '\0' && format[i + 1] == '\0'))
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
		{
			j += our_putchar(format[i]);
			i++;
			continue;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			j += our_putchar('%');
		}
		else if (format[i + 1] == 'c')
		{
			j += our_putchar(va_arg(args, int));
		}
		else if (format[i + 1] == 's')
		{
			str = va_arg(args, char*);
			j += write_strings(str);
		}
		else if (format[i + 1] == 'i' || format[i + 1] == 'd')
			j += write_numbers(va_arg(args, int));
		else
		{
			j += our_putchar(format[i]);
			i++;
			continue;
		}
		i += 2;
	}
	va_end(args);
	return (j);
}

/**
 * write_strings -function that prints strings
 * @str: input string to be printed
 * Return: number of characters printed
 */
int write_strings(char *str)
{
	const char *c = "(null)";
	int i = 0;

	if (str == NULL)
	{
		while (*c)
		{
			i += our_putchar(*c);
			c++;
		}
	}
	else
	{
		while (*str)
		{
		i += our_putchar(*str);
		str++;
		}
	}
	return (i);
}

/**
 * write_numbers -function that writes numbers
 * @nums: integer to be printed
 * Return: numbers printed
 */
int write_numbers(int nums)
{
	unsigned int positive_nums;
	unsigned int temp;
	int length = 1;

	int num_chars = 0;

	if (nums < 0)
	{
		num_chars += our_putchar('-');
		positive_nums = -nums;
	}
	else
	positive_nums = nums;

	temp = positive_nums;

	while (temp /= 10)
	{
		length *= 10;
	}
	for (; length; length /= 10)
	{
		num_chars += our_putchar(((positive_nums / length) % 10) + '0');
	}
	return (num_chars);
}

