#include "shell.h"

/**
 * herban_envp - prints environment variables
 * @args: array of argument
 * @envp: array of environment variables
 * Return: 1 on success
 */
int herban_envp(char ** args, char **envp)
{
	int i = 0, len;

	while (envp[i] != NULL)
	{
		len = _strlen(envp[i]);
		write(STDOUT_FILENO, envp[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	fre_array(args);
	return (1);
}

/**
 * herban_built - checks for builtin commands and executes them
 * @args: arrays of arguments
 * @envp: array of environment variables
 * Return: 1 on success
 */
int herban_built(char **args, char **envp)
{
	built_t b_ins[] = {
		{"env", herban_env},
		{"exit", herban_exit},
		{NULL, NULL}
	};
	int i;

	if (args[0] == NULL)
		return (0);
	for (i = 0; i < 2; i++)
	{
		if (_strcmp2(args[0], b_ins[i].cmd) == 0)
		{
			return (b_ins[i].f(args, envp));
			break;
		}
	}
	return (0);
}
