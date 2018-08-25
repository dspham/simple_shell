
#include "holberton.h"

/**
 * main - simple shell
 * @argc: counts of arguments
 * @argv: string containing the arguments
 * @environ: environment variables
 * Return: 0 on success
 */
int main(int argc, char **argv, char **environ)
{
	int read_c = 1, i, temp; /* number of bytes read */
	int status, error;
	size_t nbytes = 200; /* number of bytes for the stream */
	char *string, *full_path; /* command line */
	pid_t child;
	char **command = NULL, **path_array = NULL;

	/* Handle non-interactive mode */
	if (argc > 1)
		string = argv[1];

	/* Interactive mode */
	/* Programs runs until Ctrl+D is pressed */
	while (read_c != EOF)
	{
		/* Display a prompt */
		write(STDIN_FILENO, "#cisfun$ ", 9);

		/* Allocated memory for the string command */
		string = malloc(nbytes + 1);

		/* Get user input */
		read_c = getline(&string, &nbytes, stdin);
		if (read_c == -1)
		{
			exit(90);
			printf("getline() failed");
		}
		else if (read_c == 1)
			continue;
		command = splitstring(string);
		for (i = 0; command[i] != NULL; i++)
			;

		if (strcmp(command[0], "env") == 0)
		{
			printenviron(environ);
			continue;
		}

		if (strcmp(command[0], "exit") == 0)
		{
			if (command[1] == NULL)
				temp = 0;
			else
				temp = atoi(command[1]);
			i = 0;
			while (command[i] != NULL)
			{
				free(command[i]);
				i++;
			}
			free(command);
			__exit(temp);
		}

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

			// free(command);
			// free(string);
		}
		else if (read_c == 1)
		{
			printf("./shell: No such file or directory\n");

			// free(command);
			// free(string);
		}
		else
			exec_path(path_array, command);
	}
	return (0);
}
