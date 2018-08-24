#include <stdlib.h>
<<<<<<< HEAD
=======
#include <stdio.h>

>>>>>>> 84230d5d8d2d8466c0dd240e253818d0acc1995d
/**
 * _getenv - gets an environment variable
 * @name: name of the variable
 *
 * Return: the value of the variable
 */
char *_getenv(const char *name)
{
	extern char **environ;
	unsigned int i, j;

	/* Loop through the environment string */
	i = 0;
	while (environ[i] != NULL)
	{
<<<<<<< HEAD
		/* While environ[i][j] matches name[j] */
		j = 0;
=======
		printf("%s\n", environ[i]);
		/* While environ[i][j] matches name[j] */
		j = 0;


>>>>>>> 84230d5d8d2d8466c0dd240e253818d0acc1995d
		while (environ[i][j] == name[j] && name[j] != '\0')
			j++;

		if (environ[i][j] == '=' && name[j] == '\0')
		{
			/* return the address of environ[i][j + 1] */
<<<<<<< HEAD
=======
			printf("%s\n", &environ[i][j+1]);
>>>>>>> 84230d5d8d2d8466c0dd240e253818d0acc1995d
			return (&environ[i][j + 1]);
		}

		i++;
	}

	/* Otherwise, return NULL */
	return (NULL);
}
