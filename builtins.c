#include "holberton.h"
/**
 * print_env - print the current environment
 * @env: environment
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
 * _exit - exit a program
 * @status:
 * Return: none
 */
int __exit(int status)
{
    exit(status);
}
