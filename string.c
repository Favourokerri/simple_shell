#include "shell.h"

/**
 *_strdup - returns pointer to allocated space containing copy of string
 *@str: string that will be copied into the space
 *
 *Return: pointer to allocated space
 */
char *_strdup(char *str)
{
	int i = 0, len = 0;
	char *s;

	if (str == NULL)
		return (NULL);

	while (*(str + i) != '\0')
	{
		len++;
		i++;
	}

	i = 0;
	s = malloc(sizeof(char) * len + 1);

	if (s == NULL)
		return (NULL);

	while (*(str + i) != '\0')
	{
		*(s + i) = *(str + i);
		i++;
	}
	*(s + i) = '\0';
	return (s);
}

/**
 * _concatenate - concatenates two strings
 * @concat: memory space to concatenate the strings
 * @s1: str 1
 * @s2: str 2
 * Return: pointer to concatenated memory space
 */

char *_concatenate(char *concat, char *s1, char *s2)
{
	int con_cnt = 0, str_cnt = 0;

	while (*(s1 + str_cnt) != '\0')
	{
		*(concat + con_cnt) = *(s1 + str_cnt);
		con_cnt++;
		str_cnt++;
	}

	str_cnt = 0;
	while (*(s2 + str_cnt) != '\0')
	{
		*(concat + con_cnt) = *(s2 + str_cnt);
		con_cnt++;
		str_cnt++;
	}
	*(concat + con_cnt) = '\0';
	return (concat);
}

/**
 * _strlen - func to return the length of a string
 * @s: str param
 * Return: len of the string
 */

int _strlen(char *s)
{
	int len = 0, i = 0;

	if (s == NULL)
		return (-1);

	while (s[i] != '\0')
	{
		len++;
		i++;
	}

	return (len);

}

/**
 * _strconcat - appends src to the dest string
 * @s1: string s1
 * @s2: string s2
 * Return: concatenated string
 */
char *_strconcat(char *s1, char *s2)
{
	int len1 = 0, len2 = 0;
	char *concat;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		*s1 = '\0';
	}
	if (s2 == NULL)
	{
		s2 = malloc(sizeof(char));
		if (s2 == NULL)
			return (NULL);
		*s2 = '\0';
	}

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	concat = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concat == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}

	return (_concatenate(concat, s1, s2));
}


/**
 * _strcmp - Compares pointers to two strings.
 * @str1: A pointer to the first string to be compared.
 * @str2: A pointer to the second string to be compared.
 * Return: If str1 < str2, the negative difference of the first char
 */
int _strcmp(char *str1, char *str2)
{
	while ((*str1 == *str2) && *str1 != '\0' && *str2 != '\0')
	{
		str1++;
		str2++;
	}

	if ((*str1 == '\0') && (*str2 == '\0'))
		return (0);
	else if (*str1 > *str2)
		return ((int)(*str1 - *str2));
	else
		return ((int)(*str1 - *str2));
}
