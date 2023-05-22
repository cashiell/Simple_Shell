#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - program that executes the command ls -l /tmp in 5 different child
 * processes. Each child should be created by the same process (the father).
 * Wait for a child to exit before creating a new child.
 *
 * Return: always 0.
 */
int main(void)
{
	pid_t child_pid;
	char *exec[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *envp[] = {NULL};
	int i = 0, status;

	while (i < 5)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: ");
			return (1);
		}

		if (child_pid == 0)
		{
			printf("This is child %d executing\n", getpid());
			printf("This is his parent: %d\n", getppid());
			execve(exec[0], exec, envp);
			if (execve(exec[0], exec, envp) == -1)
			{
				perror("Error: ");
				return (1);
			}
		}
		wait(&status);
		printf("I'm handling over now!\n");
		i++;
	}
	printf("Finally, they're done executing!\n");

	return (0);
}
