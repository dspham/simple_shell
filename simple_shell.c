#include "holberton.h"

/**
 * main - simple shell
 * @argc: counts of arguments
 * @argv: string containing the arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int read_c = 0; /* number of bytes read */
	size_t nbytes = 200; /* number of bytes for the stream */
	char *string; /* command line */
	char **command = NULL;
	char *error;

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
			if (isatty(0))
				write(STDOUT_FILENO, "\n", 1);

			free(string);
			exit(90);
		}
		/* Loop again if user just pressed newline */
		else if (read_c == 1)
			continue;

		command = splitstring(string);

		if (command == NULL)
			continue;

		/* Built-in printenv */
		if (_strcmp(command[0], "env") == 0)
		{
			printenviron(environ, command);
			continue;
		}

		/* Built-in exit */
		if (_strcmp(command[0], "exit") == 0)
		{
			free(string);
			__exit(command);
		}

		/* check if str is in directory */
		if (access(command[0], X_OK) == 0)
			exec_cmd(command);
		else if (read_c > 1)
		{
			if (exec_path(command) == 1)
			{
				error = ": command not found\n";
				write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
				write(STDOUT_FILENO, error, _strlen(error));
			}
		}
		else
		{
			error = ": command not found\n";
			write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
			write(STDOUT_FILENO, error, _strlen(error));
		}
	}
		free(command);
		free(string);

	return (0);
}
