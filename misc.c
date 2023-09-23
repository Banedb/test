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

/**
 * free_args - free memory before abrupt exit
 * @args: strings array
 */
void free_args(char **args)
{
	int i;

	if (mark == 0)
	{
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		if (args)
			free(args);
		mark = 1;
	}
}


/**
 * _realloc - h
 * @ptr: input as a string
 * @old_size: stream to be read from
 * @new_size: ..
 * Return: pointer to new address
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	void *buffer;
	char *dupp, *tide;

	if (new_size == old_size)
		return (ptr);
	if (!ptr)
	{
		buffer = malloc(new_size);
		if (buffer == NULL)
			return (NULL);
		return (buffer);
	}
	if (!new_size && ptr)
		return (free(ptr), NULL);
	dupp = ptr;
	buffer = malloc(sizeof(*dupp) * new_size);
	if (buffer == NULL)
		return (free(ptr), NULL);
	tide = buffer;
	for (i = 0; i < old_size && i < new_size; i++)
		tide[i] = *dupp++;
	free(ptr);
	return (buffer);
}
