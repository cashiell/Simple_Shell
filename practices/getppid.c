#include <stdio.h>
#include <unistd.h>
#define PID_MAX_LIMIT 41367
/**
 * main - pid
 *
 * Return: always 0
 */
int main(void)
{
	pid_t my_ppid, my_pid;


	my_pid = getpid();
	my_ppid = getppid();
	printf("%u\n", my_pid);
	printf("%u\n", my_ppid);
	printf("%u\n", PID_MAX_LIMIT);

	return (0);
}
