#include "herban.h"

/**
 * herban_exit - exits the shell
 * @args: arguments
 * @env: environment variables
 * Return: 1 on success
 */
int herban_exit(char **args, char **env)
{
	int status = 0;
	(void) env;

	if (args[1])
		status = atoi(args[1]);
	free_array(args);
	exit(status);
}

/**
 * err_exit - exits due to an error after printing the error
 * @argv: arguments
 * @status: unused
 * Return: nothing
 */
void err_exit(char *argv, int status)
{
	(void) status;

	perror(argv);
	exit(0);
}
