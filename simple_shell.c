#include "holberton.h"
/**
 * main - simple shell
 *
 * Return: 0 on success
 */

int main(void)
{
	int read_c; /* number of bytes read */
	size_t nbytes = 200; /* number of bytes for the stream */
	char *string; /* command line */

	/* Display a prompt */
	write(STDIN_FILENO, "#cisfun$ ", 9);

	/* wait for the user to type a command */
	string = malloc(nbytes + 1);
	if (string == NULL)
		return (1);

	/* get user input */
	read_c = getline(&string, &nbytes, stdin);
	if (read_c == -1)
	{
		exit(90);
		printf("getline() failed");
	}

	return (0);
}
