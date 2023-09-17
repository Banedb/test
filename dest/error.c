#include "shell.h"
/**
 * err_gen - sends custom error message to stderr
 * @argv: ..
 * @err_no: error code
 *
 * Return: error code
 */
int err_gen(char **argv, int err_no)
{
	char *errmsg = NULL;

	switch (err_no)
	{	case 127:
		errmsg = error_127(argv);
		break;
	}
	
	if (errmsg)
	{
		write(STDERR_FILENO, errmsg, _strlen(errmsg));
		free(errmsg);
	}
	return (err_no);

}
