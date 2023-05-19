#include <stdio.h>

/**
 * main - prints "$ "
 *
 * Return: alway 0
 */
int main(void)
{
	char *lineptr = NULL;
	size_t n;

	printf("$ ");
	getline(&lineptr, &n, stdin);
	printf("%s", lineptr);

	return (0);
}
