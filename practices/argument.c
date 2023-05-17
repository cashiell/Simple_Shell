#include <stdio.h>

/**
 * main - program that prints all the arguments without using ac
 *
 * Return: always 0
 */
int main(__attribute__((unused)) int ac, char **av)
{
	int i;

	for (i = 0; av[i] != NULL; i++)
	{
		if (i == 0)
			continue;
		printf("%s\n", av[i]);
	}
	printf("I printed %d arguments!\n", i - 1);
	return (0);
}
