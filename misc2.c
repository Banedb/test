#include "shell.h"
/**
 * _getline - gets input from stream.
 * @lineptr: input as a string
 * @n: size of input, resizable by the function
 * @stream: stream to be read from
 *
 * Return: n of chars read || -1 on error
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t result, capacity = 130;
	int readbytes;
	char databuf = ' ', *buf;

	input = 0;
	if (lineptr == NULL || n == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	if (input == 0)
		fflush(stream);
	else
		return (-1);
	buf = malloc(capacity);
	if (!buf)
		return (-1);
	for (; databuf != '\n'; input++)
	{
		readbytes = read(STDIN_FILENO, &databuf, 1);
		buf = readb(readbytes, buf, input, capacity);
		buf[input] = databuf;
	}
	buf[input] = '\0';
	gethelp(lineptr, buf, n, input, capacity);
	result = input;
	if (readbytes != 0)
		input = 0;
	return (result);
}


/**
 * gethelp - helper function
 * @lp: input as a string
 * @n: size of input, resizable by the function
 * @buf: stream to be read from
 * @input: ..
 * @capacity: ..
 */
void gethelp(char **lp, char *buf, size_t *n, ssize_t input, ssize_t capacity)
{
	if (*lp == NULL)
	{
		if (input > capacity)
			*n = input;
		else
			*n = capacity;
		*lp = buf;
	}
	else if ((ssize_t)*n < input)
	{
		if (input > capacity)
			*n = input;
		else
			*n = capacity;
		*lp = buf;
	}
	else
	{
		_strcpy(*lp, buf);
		free(buf);
	}
}







/**
 * readb - helper function
 * @readbytes: input as a string
 * @buf: stream to be read from
 * @input: ..
 * @capacity: ..
 * @Return: ..
 */
char *readb(int readbytes, char *buf, ssize_t input, ssize_t capacity)
{
	if (readbytes == -1 || (readbytes == 0 && input == 0))
	{
		free(buf);
		return (NULL);
	}
	if (readbytes == 0 && input != 0)
	{
		input++;
		return (NULL);
	}
	if (input >= capacity)
		buf = _realloc(buf, input, input + 1);
	return (buf);
}
