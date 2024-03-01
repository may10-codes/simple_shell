#include "main.h"

/**
 * our_strchr -looks for an occurence of a
 * character in a string
 * @str: string to search in
 * @c: character to search for
 * Return: point to the character beingg searched
 * for or NULL if character is not found
 */
char *our_strchr(const char *str, int c)
{
    if (str == NULL)
        return (NULL);

    while (*str)
    {
        if (*str == (char) c)
            return ((char *) str);
        str++;
    }
    return (NULL);
}

/**
 * our_strncmp -mimics standard strncmp and compares
 * at most the first n characters of two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: maximum number of characters to compare
 * Return: 0 if the first n characters of s1 and s2 are equal or
 * negative value if first differing character in s1 is < than s2 or
 * positive value if the first differing character in s1 is > than s2
 */
int our_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i = 0;

    while (i < n && s1[i] == s2[i])
    {
        if (s1[i] == '\0')
            return (0);
        i++;
    }

    if (i == n)
        return (0);
    return ((int)(s1[i] - s2[i]));
}

/**
 * our_strsep - mimics strsep function by extracting tokens
 *from a string delimited by a specified delimiter *
 * @stringp: pointer to a pointer to the input string
 * @delim: delimiter used to separate the tokens
 * Return: pointer to the first token found in the input string
 */
char *our_strsep(char **stringp, const char *delim)
{
    char *str;
    bool is_delim;
    char *token_start;
    const char *d;
    size_t token_len = 0;

    if (stringp == NULL || delim == NULL || *delim == '\0')
        return (NULL);

    str = *stringp;
    token_start = str;

    while (*str != '\0')
    {
        is_delim = false;

        for (d = delim; *d != '\0'; d++)
        {
            if (*str == *d)
            {
                is_delim = true;
                break;
            }
        }

        if (is_delim)
        {
            *stringp = str + 1;
            return (token_start);
        }

        str++;
        token_len++;
    }
    *stringp = NULL;
    return (token_len > 0 ? token_start : NULL);
}

/**
 * our_strncat - mimics the standard strncat function
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 * @n: maximum number of characters from src to concatenate
 * Return: pointer to resulting concatenated string
 */
char *our_strncat(char *dest, const char *src, size_t n)
{
    char *dest_start = dest;

    while (*dest != '\0')
    {
        dest++;
    }
    while (*src != '\0' && n > 0)
    {
        *dest++ = *src++;
        n--;
    }

    *dest = '\0';

    return (dest_start);
}

/**
 * our_strncpy - entry point mimics standard strncpy function
 * @dest: pointer to destination buffer
 * @src: pointer to the source string
 * @n: maximum number of characters to copy from src
 * Return: pointer to the destination buffer
 */
char *our_strncpy(char *dest, const char *src, size_t n)
{
    char *dest_start = dest;

    while (*src != '\0' && n > 0)
    {
        *dest++ = *src++;
    n--;
    }
    while (n > 0)
    {
        *dest++ = '\0';
        n--;
    }

    return (dest_start);
}

