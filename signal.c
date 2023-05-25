#include "herban.h"

/**
 * signal_handler - reprints prompt when signal ctrl+D is captured
 * @signo: signal number
 */
void signal_handler(int signo)
{
	if (signo == SIGINT || signo == SIGQUIT || signo == SIGTERM)
	{
		write(STDOUT_FILENO, "\n", 1);
		write(STDOUT_FILENO, "Herban$ ", 8);
	}
}
