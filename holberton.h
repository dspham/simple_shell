#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

/* prototypes */
char **splitstring(char *buffer);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
char *_getenv(const char *name);
char **tok_path(void);
char *path_concat(char *s1, char *s2);
void printenviron(char **environ);
int __exit(int status);
char exec_path(char **path_array, char **command);
char exec_cmd(char **command);

/* structures */
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description - signly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/**
 * struct stat - stat output
 * @st: directory check
 */
struct stat st; /* structure of stat output */

/* global variables */
extern char **environ;

#endif /* _HOLBERTON_H_ */
