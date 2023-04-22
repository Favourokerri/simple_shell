#include "shell.h"

/**
 * tens_place - funct to finds the multiplication factor of tens
 * @i: index of where a number starts in the string
 * @s: the string pointer
 * Return: the tens multiplier
 */

int tens_place(int i, char *s)
{
	double tens = 1;

	while (s[i] >= '0' && s[i] <= '9')
	{
		tens *= 10;
		i++;
	}
	tens /= 10;
	return ((int) tens);
}

/**
 * print_int - prints an integer
 * @num: the number to turn into a string
 * Return: number of characters printed to stdout
 */

char *print_int(int num)
{
	int tensint = num;
	char *integer;
	int tens = 1;
	int i = 0;

	integer = malloc(33);
	if (integer == NULL)
		return (NULL);
	if (num == 0)
	{
		integer[i] = 0 + '0';
		return (integer);
	}
	num = num / 10;

	while (num != 0)
	{
		num = num / 10;
		tens *= 10;
	}

	while (tens != 0)
	{
		integer[i] = (tensint / tens) + '0';
		tensint = tensint % tens;
		tens /= 10;
		i++;
	}
	integer[i] = '\0';
	return (integer);
}
