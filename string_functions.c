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

/**
 * str_concat - concatenates two strings to newly allocated memory space
 * @s1: first string
 * @s2: string to be appended
 * Return: pointer to the new string; otherwise NULL
 */
char *str_concat(char *s1, char *s2)
{
	char *concat_str;
	int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for (i = 0; s1[i] != '\0'; i++)
		;
	for (j = 0; s2[j] != '\0'; j++)
		;
	concat_str = malloc((sizeof(char) * i) + (sizeof(char) * j) + 1);
	if (concat_str == NULL)
		exit(0);
	for (i = 0; s1[i] != '\0'; i++)
		concat_str[i] = s1[i];
	for (j = 0; s2[j] != '\0'; j++)
		concat_str[i + j] = s2[j];
	concat_str[i + j] = '\0';
	return (concat_str);
}
