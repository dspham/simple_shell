#include "holberton.h"


/**
 * printenviron - print the current environment
 * @environ: environment
 * @command: array of arguments
 * Return: none
 */
void printenviron(char **environ, char **command)
{
	int i;

	if (command[1])
		write(1, "No such file or directory\n", 26);
	else
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			write(1, environ[i], _strlen(environ[i]));
			write(1, "\n", 1);
		}
	}
}

/**
 * __exit - exit a program
 * @command: array of arguments
 * Return: none
 */
int __exit(char **command)
{
	static int i;
	int temp;

	if (command[1])
		printf("arg %s\n", command[1]);

	for (i = 0; command[i] != NULL; i++)

	if (command[1] == NULL)
		temp = 0;
	else if (temp < INT_MAX)
		temp = _atoi(command[1]);
	else
		printf("%d: exit: Illegal Number: %s", i, command[1]);
	printf("%d\n", temp);
	while (command[i] != NULL)
	{
		free(command[i]);
		i++;
	}
	printf("%d\n", temp);
	free(command);
	_exit(temp);
}
