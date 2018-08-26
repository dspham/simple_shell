#include "holberton.h"

/**
 * exec_path - executes arguments concatenated to path directory
 * @path_array: tokenized array of directory
 * @command: array of arguments
 * Return: the directory with argument
 */
char exec_path(char **path_array, char **command)
{
int i;
int status, error;
char *full_path;
pid_t child;

	/* Store the path directories into an array */
	path_array = tok_path();
	/* check if the concatenation of the command with */
	/* the elements of the path array exist */
	for (i = 0; path_array[i] != '\0'; i++)
	{
		full_path = path_concat(path_array[i], command[0]);
		if (access(full_path, X_OK) == 0)
		{
			/* program is present */
			/* fork program */
			child = fork();
			if (child == 0)
			{
				/* execute the command in child */
				error = execve(full_path, command, NULL);
				if (error == -1)
					perror("Error:");
				else
					return (0);
			}
			wait(&status);
			break;
		}
	}
	return (*full_path);
}
