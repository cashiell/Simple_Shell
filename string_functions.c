#include "herban.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1 to be compared
 * @s2: string 2 that 1 is to be compared with
 * Return: int < 0 if 1 < 2, int > 0 if 1 > 2, int = 0 if both are equal
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
		i += 1;
	if (s1[i] == '\0')
		return (1);
	else
		return (-1);
}

/**
 * _strcmp2 - compares two strings
 * @s1: string 1 to be compared
 * @s2: string 2 that 1 is to be compared with
 * Return: int < 0 if 1 < 2, int > 0 if 1 > 2, int = 0 if both are equal
 */
int _strcmp2(const char *s1, const char *s2)
{
	int i, result;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		result = s1[i] - s2[i];
		if (result == 0)
			continue;
		else
			break;
	}
	if (s1[i] == '\0' || s2[i] != '\0')
		result = s1[i] - s2[i];

	return (result);
}

/**
 * _strlen - returns the length of a string
 * @s: the string
 * Return: length of s
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	return (i);
}
