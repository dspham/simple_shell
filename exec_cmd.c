#include "holberton.h"

/**
 * exec_cmd - executes tokenized commands
 * @command: array of arguments
 * Return: none
 */
char exec_cmd(char **command)
{
	int status, error;
	pid_t child;

	/* program is present */
	/* fork program */
	child = fork();
	if (child == 0)
	{
		/* execute the command in child */
		error = execve(command[0], command, NULL);
		if (error == -1)
			perror("Error:");
		else
			return (0);
	}
	wait(&status);

	return (0);

	// free(command);
	// free(string);
}
