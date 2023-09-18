#include "shell.h"
/**
 * sig_h - handle reception of SIGINT signal
 * @signum: signal number
 */
void sig_h(int signum)
{
	write(STDIN_FILENO, "\n$ ", 3);
	(void) signum;
}
