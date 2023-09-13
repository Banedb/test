#include "shell.h"

/**
 * check_err - checks for getline error or EOF or C-d
 *
 * return:
 */
void check_err(void)
{
	char *lineptr = NULL;
	size_t n = 0; /*initial bufsize resizable by gl to accommodate input*/
	ssize_t charc/*actual n of chars gl read from the input stream.*/;

      /*getline puts what was typed into lineptr*/
	charc = getline(&lineptr, &n, stdin);
       /* check if the gl function failed or reached EOF or user use CTRL + D */
      /*getline returns total n of chars read by the function or -1 on error*/
	if (charc == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(lineptr);
		exit(EXIT_FAILURE);/*Exit shell on error*/
	}
	free(lineptr);
}
