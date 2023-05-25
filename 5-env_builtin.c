#include "herban.h"

/**
 * herban_env - prints environment variables
 * @args: arguments
 * @env: environment variables
 * Return: 1 on success
 */
int herban_env(char **args, char **env)
{
	int i = 0, len;

	while (env[i] != NULL)
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	free_array(args);
	return (1);
}

/**
 * herban_built - checks for built-in commands and execute them
 * @args: array of arguments
 * @env: environment variables
 * Return: 1 on success
 */
int herban_built(char **args, char **env)
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
		return (b_ins[i].f(args, env));
			break;
		}
	}
	return (0);
}
