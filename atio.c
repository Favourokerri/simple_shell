#include "shell.h"

/**
 * _atoi - converts a string into an integer
 * @str: string to convert to integer
 * Return: the integer value of the converted string
 */
int _atoi(char *str)
{
	int index, len = 0;
	int power = 1;
	unsigned int result = 0;
	int is_negative = 0;
	int negative_count = 0;
	int positive_count = 0;

	while (str[len] != '\0')
	{
		if (str[len] > '9' || str[len] < '0')
			return (-1);
		len++;
	}
	while ((str[index] > '9' || str[index] < '0') && str[index] != '\0')
	{
		if (str[index] == '-')
			negative_count++;
		if (str[index] == '+')
			positive_count++;
		index++;
	}
	if (str[index] == '\0')
		return (0);

	if ((negative_count % 2) != 0)
		is_negative = 1;

	power = tens_place(index, str);
	while (str[index] >= '0' && str[index] <= '9')
	{
		result += ((str[index] - '0') * power);
		power /= 10;
		index++;
	}
	if (is_negative == 1)
		result *= -1;

	return ((int) result);
}
