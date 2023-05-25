#include "herban.h"

/**
 * prompt - prompts the user for commands
 * @ptr: ptr will hold the string of commands
 * Return: 1 for success
 */
int prompt(char **ptr)
{
	size_t size = 0;
	int len;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "Herban$ ", 8);
	len = getline(ptr, &size, stdin);
	if (len == EOF)
		free_cptrn(-1, 1, *ptr);
	(*ptr)[len - 1] = '\0';
	if (*(*ptr) == '\0' || (*(*ptr) == '.' && (*ptr)[1] == '\0'))
	{
		free_cptrn(99, 1, *ptr);
		return (-1);
	}
	else
		return (1);
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: list of arguments
 * @envp: list of environment variables
 * Return: Always 0
 */
int main(__attribute__((unused)) int argc, char **argv, char **envp)
{
	char *ptr = NULL;
	char **string = NULL;
	int status;
	pid_t parent;

	while (1)
		{
		ptr = NULL;
		signal(SIGINT, signal_handler);
		if (prompt(&ptr) == -1)
			continue;
		string = strtow(ptr);
		if (!string)
		{
			free_cptrn(99, 1, ptr);
			continue;
		}
		free_cptrn(99, 1, ptr);
		if (herban_built(string, envp))
			continue;
		parent = fork();
		if (parent == 0)
		{
			check_path(string, envp);
			if (execve(string[0], string, NULL) == -1)
			{
				perror(*argv);
				free_array(string);
				exit(0);
			}
		}
		else
		{
			free_array(string);
			if (!wait(&status))
				break;
		}
	}
	return (0);
}
