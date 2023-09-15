#include "shell.h"

/**
 * get_input - gets input from stdin using getline
 * Return: pointer to the input
 */
char *get_input(void)
{
	char *user_input = NULL;
	size_t n = 0; /*initial bufsize resizable by gl to accommodate input*/
	ssize_t charc/* actual n of chars gl read from the input stream */;

      /*getline puts what was typed into line*/
	charc = getline(&user_input, &n, stdin);
       /* check if getline failed or reached EOF or on CTRL + D */
      /*getline returns total n of chars read by the function or -1 on error*/
	if (charc == -1)
	{
		write(STDERR_FILENO, "\n", 1);
		free(user_input);
		exit(0);
	}
	return (user_input);
}

/**
 * tokenizer - splits line into an array of tokens
 * @line: line to be split
 *
 * Return: pointer to the array
 */
char **tokenizer(char *line)
{
	int tcount;
	const char *delim = " \t\n";
	char *line_copy = NULL, *token, **token_array;

	line_copy = _strdup(line);
	/* split line_copy into an array of words */
	token = strtok(line_copy, delim);
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
	token = strtok(line, delim);
	for (tcount = 0; token != NULL; tcount++)
	{
		token_array[tcount] = _strdup(token);
		token = strtok(NULL, delim);
	}
	token_array[tcount] = NULL;

	free(line_copy);

	return (token_array);
}
/*The code does not handle the case where the input string is empty */
/*or contains only whitespace. In such cases, the tokenizer function */
/* should return NULL or an empty token_array.*/
