#include "holberton.h"
/**
 * splitstring - string tokenizes a command
 * @buffer: buffer to hold the command
 * Return: array of string tokens
 */

char **splitstring(char *buffer)
{
    char **stored = NULL;
    char *token;
    int count = 0;
    int element = 0;
    char *tmpbuffer = 0;
    //char separators = {' ' , '\t', '\n'};

/*     while (buffer[count] != '\n')
    {
        if (buffer[count] != ' ')
        {
            if (buffer[count + 1] == ' ' || buffer[count + 1] == '\n')
            {
                element++;
            }
        }
        count++;
    } */

    /* make a copy of the buffer */
    tmpbuffer = strdup(buffer);
    /*tokenize the temp buffer */
    strtok(tmpbuffer, " \n\t");
    /* tokenize the rest of the arguments */
    while (strtok(NULL, " \n\t"))
        element++;

    stored = malloc(sizeof(char *) * (element + 1));
    token = strtok(buffer, " \n");
    printf("token:%s\n", token);
    //buffer[count] = '\0';
    count = 0;
    stored[count] = token;
    for (count = 1; count < element + 1; count++)
    {
        token = strtok(NULL, " \n");
        printf("token:%s\n", token);
        stored[count] = token;
    }
    stored[count] = NULL;
    return (stored);
}
