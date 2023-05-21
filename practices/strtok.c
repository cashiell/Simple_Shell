#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * main - splits a string and returns an array of each word of the string.
 *
 * Return: always 0.
 */
int main(int argc, char **argv)
{
	char *str, *holder;
	int j;

	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s string delimiter(s)\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (j = 1, str = argv[1]; ; j++, str = NULL)
	{
		holder = strtok(str, argv[2]);
		if (holder == NULL)
		{
			printf("No more string to print\n");
			break;
		}
		printf("%s\n", holder);
	}

	return (0);
}
