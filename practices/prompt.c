#include "herban.h"

/**
 * main - command line interpreter
 *
 * Return: always 0
 */
int main(void)
{
	char *token, *argv[] = {NULL, NULL}, *line = NULL, *envp[] = {NULL};
	int status, len, argc = 0, myeof = 1;
	size_t n;
	pid_t child_pid;

	while (myeof)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "herban$ ", 8);
		len = getline(&line, &n, stdin);
		if (len == -1)
		{
			perror("Error");
			return (1);
		} token = strtok(line, " \t\n");
		while (token != NULL && argc < 10)
		{
			argv[argc++] = token;
			token = strtok(NULL, " \t\n");
		} argv[argc] = NULL;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("./shell");
			return (1);
		} else if (child_pid == 0)
		{
			if (argc == 1)
			{
				if (execve(argv[0], argv, envp) == -1)
				{
					perror("./shell");
					return (1);
				}
			}
			write(2, "./shell: No such file or directory\n", 35);
			myeof = 0;
		} wait(&status);
	} free(line);
	return (0);
}
