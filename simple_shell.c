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
			write(1, "\n", 1);
			exit(90);
			printf("getline() failed");
		}
		else if (read_c == 1)
			continue;
		command = splitstring(string);
		if (_strcmp(command[0], "env") == 0)
		{
			printenviron(environ);
			continue;
		}

		if (_strcmp(command[0], "exit") == 0)
		{
			__exit(command);
		}

		/* check if str is in directory */
		if (stat(string, &st) == 0)
		{
			exec_cmd(command);
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
