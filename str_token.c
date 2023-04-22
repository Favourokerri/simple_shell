#include "shell.h"

/**
 * token_lenght - Locates the delimiter index marking the end
 *		of the first token contained within a string.
 * @str: The string to be searched.
 * @delim: The delimiter character.
 *
 * Return: The delimiter index marking the end of
 *         the intitial token pointed to be str.
 */
int token_lenght(char *str, char *delim)
{
	int i = 0;

	int length = 0;

	while (str[i] != '\0' && str[i] != *delim)
	{
		length++;
		i++;
	}

	return (length);
}

/**
 * count_tokens - Counts the number of delimited
 *		words in  a string.
 * @str: The string.
 * @delim: The delimiter character.
 *
 * Return: The number of words contained within str.
 */
int count_tokens(char *str, char *delim)
{
	int index, tokens = 0, len = 0;

	for (index = 0; *(str + index); index++)
		len++;

	for (index = 0; index < len; index++)
	{
		if (*(str + index) != *delim)
		{
			tokens++;
			index += token_lenght(str + index, delim);
		}
	}

	return (tokens);
}

/**
 * **_strtok - Tokenizes a string.
 * @str: The string to be tokenized.
 * @delim: The delimiter character to tokenize the string by.
 *
 * Return: A pointer to an array containing the tokenized words.
 */
char **_strtok(char *str, char *delim)
{
	char **tokens = NULL;
	int index = 0, num_tokens, t, token_len, l;

	num_tokens = count_tokens(str, delim);
	if (num_tokens == 0)
		return (NULL);

	tokens = malloc(sizeof(char *) * (num_tokens + 2));
	if (!tokens)
		return (NULL);

	for (t = 0; t < num_tokens; t++)
	{
		while (str[index] == *delim)
			index++;

		token_len = token_lenght(str + index, delim);

		tokens[t] = malloc(sizeof(char) * (token_len + 1));
		if (!tokens[t])
		{
			for (index -= 1; index >= 0; index--)
				free(tokens[index]);
			free(tokens);
			return (NULL);
		}

		for (l = 0; l < token_len; l++)
		{
			tokens[t][l] = str[index];
			index++;
		}

		tokens[t][l] = '\0';
	}
	tokens[t] = NULL;
	tokens[t + 1] = NULL;

	return (tokens);
}
