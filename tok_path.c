#include "holberton.h"

/**
 * tok_path - stores each directory from path into an array
 *
 * Return: address of the array
 */

char **tok_path(void)
{
	char *path, *path_cpy, *token;
	char **path_array;
	int i, token_c = 0;

	/* Initialize */
	path = _getenv("PATH");
	path_cpy = _strdup(path);
<<<<<<< HEAD
=======
	printf("copy: %s \nactual: %s\n", path_cpy, path);
>>>>>>> 84230d5d8d2d8466c0dd240e253818d0acc1995d

	/* Find memory size for array */
	token = strtok(path_cpy, ":");
	while (token)
	{
		token = strtok(NULL, ":");
		token_c++;
	}

	/* Allocate memory for array */
<<<<<<< HEAD
	path_array = malloc(sizeof(char) * (token_c + 1));
=======
	path_array = malloc(sizeof(char *) * (token_c + 1));
>>>>>>> 84230d5d8d2d8466c0dd240e253818d0acc1995d
	if (path_array == NULL)
		return (NULL);

	/* Create tokens */
	token_c = 0;
	token = strtok(path, ":");
	while (token)
	{
<<<<<<< HEAD
		++token_c;
		path_array[token_c - 1] = token;
		token = strtok(NULL, ":");
=======
		path_array[token_c - 1] = token;
		printf("%s\n", token);
		token = strtok(NULL, ":");
		++token_c;	
>>>>>>> 84230d5d8d2d8466c0dd240e253818d0acc1995d
	}
	path_array[token_c] = 0;

	return (path_array);
}
