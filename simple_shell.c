#include "holberton.h"

/**
 * main - simple shell
 * @argc: counts of arguments
 * @argv: string containing the arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int read_c = 1; /* number of bytes read */
	size_t nbytes = 200; /* number of bytes for the stream */
	char *string; /* command line */
	char **command = NULL;

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
			write(1, "\n", 1);
			exit(90);
			printf("getline() failed");
		}
		/* Loop again if user just pressed newline */
		else if (read_c == 1)
			continue;

		command = splitstring(string);

		/* Built-in printenv */
		if (_strcmp(command[0], "env") == 0)
		{
			printenviron(environ);
			continue;
		}

		/* Built-in exit */
		if (_strcmp(command[0], "exit") == 0)
		{
			__exit(command);
		}

		/* check if str is in directory */
		if (access(command[0], X_OK) == 0)
			exec_cmd(command);
		else if (read_c > 1)
		{
			if (exec_path(command) == 1)
				printf("%s: No such file or directory\n", argv[0]);
		}
		else
			printf("%s: No such file or directory\n", argv[0]);
	}

	return (0);
}
