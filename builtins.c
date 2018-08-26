#include "holberton.h"

/**
 * printenviron - print the current environment
 * @environ: environment
 * Return: none
 */
void printenviron(char **environ)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 1);
	}
}

/**
 * __exit - exit a program
 * @command: array of arguments
 * Return: none
 */
int __exit(char **command)
{
	//char **command;
	int i, temp;

	for (i = 0; command[i] != NULL; i++)	

	if (command[1] == NULL)
	temp = 0;
	else
		temp = atoi(command[1]);
	while (command[i] != NULL)
	{
		free(command[i]);
		i++;
	}
	free(command);
	_exit(temp);
}
