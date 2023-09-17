#include "shell.h"

void sig_h(int signum)
{
	write(STDIN_FILENO, "\n$ ", 3);
	(void) signum;
}
