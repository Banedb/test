#include "shell.h"

/**
 * check_err - checks for getline error or EOF or C-d
 *
 * return:
 */
int check_err(void)
{
	char *lineptr;
	size_t n = 0; /*initial buf size resizable by getline to accommodate input*/
	ssize_t charc = 0/*actual n of chars getline read from the input stream.*/;

      /*getline puts what was typed into lineptr*/
	charc = getline(&lineptr, &n, stdin);
       /* check if the getline function failed or reached EOF or user use CTRL + D */
      /*getline returns total n of chars read by the function or -1 on error*/
	if (charc == -1)
	{
		free(lineptr);
		return (-1);/*Exit shell on error*/
	}
	free(lineptr);
	return (0);
}
