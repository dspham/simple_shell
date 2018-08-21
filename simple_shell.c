#include "holberton.h"
#include <stdio.h>
/**
 * main - simple shell
 * @argc: counts of arguments
 * @argv: string containing the arguments
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	int read_c = 0; /* number of bytes read */
	int status, error;
	size_t nbytes = 200; /* number of bytes for the stream */
	char *string;		 /* command line */
	pid_t child;
	char **command = NULL;
	// char separator = [":", " ", "\n];

	struct stat st; /* structure of stat output */

	/* Handle non-interactive mode */
	if (argc > 1)
		string = argv[1];

	/* Interactive mode */
	/* Programs runs until Ctrl+D is pressed */
	do
	{
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

		/* create space for command array */
		command = malloc(sizeof(char *) * 3);
		if (command == NULL)
			return (-1);

		/* populate the array */
		command = splitstring(string);
		// command[0] = strtok(string, " ");
		// command[1] = strtok(NULL, " ");
		// command[2] = NULL;

		printf("%s\n", command[0]);
		printf("%s\n", command[1]);

		/* check if str is in directory */
		if (stat(string, &st) == 0)
		{
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
			free(command);
			free(string);
		}
		else
		{
			printf("./shell: No such file or directory\n");
			free(command);
			free(string);
		}
	} while (read_c != EOF);
	return (0);
}
