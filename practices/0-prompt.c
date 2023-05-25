#include "herban.h"

/**
 * main - command line interpreter
 *
 * Return: always 0
 */
int main(void)
{
	char *input, *arglist[2];
	int myeof = 1, len;
	size_t n = 0;
	pid_t child_pid;

	arglist[1] = NULL;
	input = malloc(MAX_CMD_LEN);
	while (myeof)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "herban$ ", 8);
			fflush(stdout);
		} len = getline(&input, &n, stdin);
		if (len == -1)
		{
			if (len == EOF)
				break;
			perror("./shell");
			return (1);
		}
		if (len > 0 && input[len - 1] == '\n')
			input[len - 1] = '\0';
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("./shell");
			return (1);
		} else if (child_pid == 0)
		{
			arglist[0] = input;

			if (execve(input, arglist, NULL) == -1)
			{
				perror("./shell");
				return (1);
			}
		} waitpid(child_pid, NULL, 0);
	} free(input);
	return (0);
}
