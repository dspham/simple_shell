#include "holberton.h"
/**
 * splitstring - string tokenizes a command
 * @buffer: buffer to hold the command
 * Return: array of string tokens
 */

char **splitstring(char *buffer)
{
    char **stored;
    char *token;
    char *tmpbuffer;
    int count = 0;
    int element = 0;

    while (buffer[count] != '\n')
    {
        if (buffer[count] != ' ')
        {
            if (buffer[count + 1] == ' ' || buffer[count + 1] == '\n')
            {
                element++;
            }
        }
        count++;
    }

    token = strtok(tmpbuffer, " \n");
    buffer[count] = '\0';
    stored = malloc(sizeof(char *) * element + 1);
    count = 0;
    stored[count] = token;
    for (count = 1; count < element + 1; count++)
    {
        token = strtok(NULL, " \n");
        stored[count] = token;
    }
    stored[count] = NULL;
    free (tmpbuffer);
    return (stored);
}
