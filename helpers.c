#include "holberton.h"
/**
 * _strcmp - compres two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: difference of bytes between the strings, otherwise 0
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

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
