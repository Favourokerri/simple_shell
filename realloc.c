#include "shell.h"

/**
 * _realloc - reallocates memory for char
 * @ptr: pointer to an array
 * Return: pointer to new memory
 */
char *_realloc(char *ptr)
{
	int i = 0;
	char *newptr;

	if (ptr == NULL)
		return (NULL);

	while (*(ptr + i) != '\n')
		i++;

	newptr = malloc(sizeof(char) * i + 1);
	if (newptr == NULL)
		return (NULL);
	i = 0;
	while (*(ptr + i) != '\n')
	{
		*(newptr + i) = *(ptr + i);
		i++;
	}
	*(newptr + i) = '\0';
	return (newptr);
}
