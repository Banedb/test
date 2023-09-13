#include "shell.h"

/**
 * get_input - gets input from stdin using getline
 */
void get_input(void)
{
	char *lineptr = NULL;
	size_t n = 0; /*initial bufsize resizable by gl to accommodate input*/
	ssize_t charc/* actual n of chars gl read from the input stream */;

      /*getline puts what was typed into lineptr*/
	charc = getline(&lineptr, &n, stdin);
       /* check if getline failed or reached EOF or on CTRL + D */
      /*getline returns total n of chars read by the function or -1 on error*/
	if (charc == -1)
	{
		write(STDERR_FILENO, "\n", 1);
		free(lineptr);
		exit(0);
	}
	tokenizer(lineptr, charc);

	free(lineptr);
}

/**
 * tokenizer - splits input string into an array of tokens
 * @lineptr: input string
 * @charc: number of chars
 *
 * Return: pointer to the array
 */
char **tokenizer(char *lineptr, ssize_t charc)
{
	int tcount, i;
	const char *delim = " \n";
	char *lineptr_copy = NULL, *token, **token_array;

	lineptr_copy = malloc(sizeof(char) * charc);
	if (!lineptr_copy)
	{
		free(lineptr_copy);
		return (NULL);
	}
	_strcpy(lineptr_copy, lineptr);
	/* split lineptr_copy into an array of words */
	token = strtok(lineptr_copy, delim);
	/* count tokens */
	for (tcount = 0; token != NULL; tcount++)
		token = strtok(NULL, delim);
	tcount++;

	/* allocate space to hold the array of strings */
	token_array = malloc(sizeof(char *) * tcount);
	if (!token_array)
	{
		free(token_array);
		return (NULL);
	}
	/* store each token in the token_array */
	token = strtok(lineptr, delim);
	for (i = 0; token != NULL; i++)
	{
		token_array[i] = malloc(sizeof(char) * strlen(token));
		_strcpy(token_array[i], token);
		token = strtok(NULL, delim);
	}
	token_array[i] = NULL;

	free(lineptr_copy);
	free(token_array);

	return (token_array);
}
