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

/**
 * _atoi - converts a string into an integer
 * @s: the string to convert
 *
 * Return: int res
 */
int _atoi(char *s)
{
	int sign = 1, i = 0;
	unsigned int res = 0;

	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	res *= sign;
	return (res);
}
