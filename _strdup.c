#include "holberton.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string parameter
 *
 * Return: pointer to a char or NULL
 */

char *_strdup(char *str)
{
	char *p;
	int n = 0;
	int i = 0;

	if (str == NULL)
		return (NULL);

	while (str[n] != '\0')
		n++;

	p = malloc((n + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);

	while (i <= n)
	{
		p[i] = str[i];
		i++;
	}

	return (p);
}
