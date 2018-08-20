#include "holberton.h"
/**
 * main - simple shell
 *
 * Return: 0 on success
 */

int main(void)
{
	/* Display a prompt and wait for the user to type a command */
	write(STRDIN_FILENO, "#cisfun$ ", 9);

	return (0);
}
