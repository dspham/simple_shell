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
	char *token, *tmptok, *tmpbuffer;
	int count = 0;
	int elements_c = 0;

	/* Check if buffer is not NULL */
	if (buffer == NULL)
		return (NULL);

	/* make a copy of the buffer */
	tmpbuffer = _strdup(buffer);

	/* Calculate the number of arguments */
	tmptok = strtok(tmpbuffer, " \t\n");
	while (tmptok)
	{
		elements_c++;
		tmptok = strtok(NULL, " \t\n");
	}

	/* Allocate memory for the array */
	array = malloc(sizeof(char *) * (elements_c + 1));

	if (elements_c > 0)
	{
		token = strtok(buffer, " \t\n");
		count = 0;
		array[count] = token;
		for (count = 1; token != NULL; count++)
		{
			token = strtok(NULL, " \t\n");
			array[count] = token;
		}
		free(tmpbuffer);
		return (array);
	}
	else
	{
		free(tmpbuffer);
		return (NULL);
	}
}
