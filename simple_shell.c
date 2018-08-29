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
	size_t nbytes = 0; /* number of bytes for the stream */
	char *string; /* command line */
	char **command = NULL;
	unsigned int line = 0;
	int exit_status = 0;

	/* Handle non-interactive mode */
	if (argc > 1)
		string = argv[1];

	/* Interactive mode */
	/* Programs runs until Ctrl+D is pressed */
	while (read_c != EOF)
	{
		string = NULL;
		/* Display a prompt */
		write(STDIN_FILENO, "#cisfun$ ", 9);

		/* Get user input */
		read_c = getline(&string, &nbytes, stdin);

		line++;
		if (read_c == -1)
		{
			//write(STDOUT_FILENO, "\n", 1);
			free(string);
			_exit(exit_status);
		}
		if (read_c == 0)
		{
			if (isatty(0))
			{
				write(STDOUT_FILENO, "\n", 1);
				continue;
			}
		}


		/* Loop again if user just pressed newline */
		else if (read_c == 1)
		{
			free(string);
			continue;
		}

		command = splitstring(string);

		if (command == NULL)
		{
			free(string);
			continue;
		}

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
		if (access(command[0], F_OK) == 0)
		{
			if (access(command[0], X_OK) == 0)
				exec_cmd(command);
			else
			{
				print_error(argv[0], command[0], line, "perm");
				exit_status = 127;
			}
		}
		else if (read_c > 1)
		{
			if (exec_path(command) == 1)
			{
				print_error(argv[0], command[0], line, "nf");
				exit_status = 127;
			}
		}
		else
		{
			print_error(argv[0], command[0], line, "nf");
			exit_status = 126;
		}
		free(string);

		free(command);
	}

	return (0);
}
