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
 * @status: status sent back to parent process
 * Return: none
 */
int __exit(int status)
{
	exit(status);
}
