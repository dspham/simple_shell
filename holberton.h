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

#endif /* _HOLBERTON_H_ */
