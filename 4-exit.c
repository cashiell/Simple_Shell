#include "shell.h"

/**
 * herban_exit - exits the shell
 * @args: arguments
 * @envp: environment variables
 * Return: 1 on success
 */
int herban_exit(char **args, char **envp)
{
	(void) envp;
	int status = 0;

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
