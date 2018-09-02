#include "holberton.h"

/**
 * _siginterrupt - interrupt from keyboard
 * @v: unused variable
 * Return: none
 */
void _siginterrupt(int __attribute__ ((unused)) v)
{
	write(1, "\n", 1);
	write(STDIN_FILENO, "#cisfun$ ", 9);
}
