#include "shell.h"

/**
 * _strlen - function to return the length of a string
 * @string: the string whose length is to be found
 * Return: the length of the string
 */

int _strlen(const char *string)
{
	int length = 0;

	while (*string != '\0')
	{
		length++;
		string++;
	}

	return (length);
}

/**
 * _strcpy - copy the content of a string
 * @dest: string to be copied to
 * @src: the source to copy from
 * Return: pointer to the copied string
 */

char *_strcpy(char *dest, const char *src)
{
	size_t index;

	for (index = 0; src[index] != '\0'; index++)
		dest[index] = src[index];
	dest[index] = '\0';
	return (dest);
}

/**
 * _strcat - concatinate two strings
 * @destination: first string
 * @source: second string
 *Return: the concatinated string
 */
char *_strcat(char *destination, const char *source)
{
	char *dest_ptr;

	const char *src_ptr;

	dest_ptr = destination;
	src_ptr = source;

	while (*dest_ptr != '\0')
	{
		dest_ptr++;
	}

	while (*src_ptr != '\0')
	{
		*dest_ptr++ = *src_ptr++;
	}

	*dest_ptr = '\0';
	return (destination);
}

/**
 * _strncat - Concatenates two strings where n number
 *            of bytes are copied from source.
 * @dest: Pointer to destination string.
 * @src: Pointer to source string.
 * @n: Number of bytes to copy from src.
 *
 * Return: Pointer to destination string.
 */
char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);  /* Calculate length of destination string */
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[i];  /* Copy n bytes from src to dest */
	}

	dest[dest_len + i] = '\0';  /* Add null terminator */
	return (dest);  /* Return pointer to concatenated string */
}

/**
 * _strncmp - compare two srtings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * @n: the number of bytes to be compared
 * Return: 1 0r -1 to indicate which string is shoter
 *		0 if they are thesame
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}

		else if (s1[i] == '\0')
		{
			return (-1);
		}

		else if (s2[i] == '\0')
		{
			return (1);
		}
	}

		return (0);
}
