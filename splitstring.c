#include "holberton.h"
/**
 * splitstring - tokenize a string and puts tokens into array
 * @buffer: buffer to hold the command
 *
 * Return: array of string tokens
 */

char **splitstring(char *buffer)
{
	char **array = NULL;
	char *token;
	int count = 0;
	int elements_c = 0;
	char *tmpbuffer = 0;

	/* Check if buffer is not NULL */
	if (buffer == NULL)
		return (NULL);

	/* Remove the new line from buffer */
	buffer = strtok(buffer, "\n");

	/* make a copy of the buffer */
	tmpbuffer = strdup(buffer);

	/* Calculate the number of arguments */
<<<<<<< HEAD
	strtok(tmpbuffer, " ");
	while (strtok(NULL, " "))
=======
	strtok(tmpbuffer, " \t");
	while (strtok(NULL, " \t"))
>>>>>>> 84230d5d8d2d8466c0dd240e253818d0acc1995d
		elements_c++;

	/* Allocate memory for the array */
	array = malloc(sizeof(char *) * (elements_c + 1));

	/* Populate the array */
<<<<<<< HEAD
	token = strtok(buffer, " ");
=======
	token = strtok(buffer, " \t");
>>>>>>> 84230d5d8d2d8466c0dd240e253818d0acc1995d
	count = 0;
	array[count] = token;
	for (count = 1; count < elements_c + 1; count++)
	{
<<<<<<< HEAD
		token = strtok(NULL, " ");
=======
		token = strtok(NULL, " \t");
>>>>>>> 84230d5d8d2d8466c0dd240e253818d0acc1995d
		array[count] = token;
	}
	array[count] = NULL;

	return (array);
<<<<<<< HEAD
}
=======
}
>>>>>>> 84230d5d8d2d8466c0dd240e253818d0acc1995d
