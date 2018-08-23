#include "holberton.h"

/**
 * main - simple shell
 * @argc: counts of arguments
 * @argv: string containing the arguments
 *
 * Return: 0 on success
 */

extern char **environ;
// void printenviron(char **environ)
// {
// 	int i;
// 	for (i = 0; environ[i] != NULL; i++)
//     {
//         write(1, environ[i], strlen(environ[i]));
//         write(1, "\n", 1);
//     }
// }
int main(int argc, char **argv)
{
	int read_c = 1; /* number of bytes read */
	int status, error;
	size_t nbytes = 200; /* number of bytes for the stream */
	char *string; /* command line */
	pid_t child;
	char **command = NULL;
	int temp;
	int i = 0;

	// printf("qwer%s\n", command[0]);
	// if (strcmp(command[0], "env") == 0)
	// {
	// 	printenviron(environ);
	// }

	struct stat st; /* structure of stat output */

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
		printf("%s\n", command[i]);

		printf("qwer%s\n", command[0]);
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
			while (command[i] != NULL)
			{
				free(command[i]);
				i++;
			}
			free(command);
			__exit(temp);
		}
		// if (!strcmp(command[0], "exit"))
		// {
		// 	free(command);
		// 	return (0);
		// }

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
		else if (read_c > 1)
		{
			printf("./shell: No such file or directory\n");

			free(command);
			free(string);
		}
	}

	return (0);
}
