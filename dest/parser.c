#include "shell.h"

/**
 * run_input - gets input from stdin using getline
 *
 * Return: pointer to the input
 */
char *run_input()
{
	char **args, *user_input = NULL, **envp = environ;
	int i;
	size_t n = 0; /*initial bufsize resizable by gl to accommodate input*/
	ssize_t charc/* actual n of chars gl read from the input stream */;

      /*getline puts what was typed into user_input*/
	charc = getline(&user_input, &n, stdin);
       /* check if getline failed or reached EOF or on CTRL + D */
      /*getline returns total n of chars read by the function or -1 on error*/
	if (charc == -1)
	{
		write(STDERR_FILENO, "\n", 1);
		if (user_input)
			free(user_input);
		exit(EXIT_FAILURE);
	}
	/* split input string and store as array */
	args = tokenizer(user_input);
	cmdexe(args, envp);
	if (isatty(STDIN_FILENO))
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
	if (args)
		free(args);
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
	if (line_copy != NULL)
	{
		token = _strtok(line_copy, delim);
		/* count tokens ie n of strings */
		for (tcount = 0; token != NULL; tcount++)
			token = _strtok(NULL, delim);
		free(line_copy);
	}
	else
		return (NULL);

	/* allocate space to hold the array of strings */
	token_array = malloc(sizeof(char *) * (tcount + 1));
	if (!token_array)
		return (NULL);
	/* store each token in the token_array */
	token = _strtok(line, delim);
	for (tcount = 0; token != NULL; tcount++)
	{
		token_array[tcount] = _strdup(token);
		token = _strtok(NULL, delim);
	}
	token_array[tcount] = NULL;
	if (line)
		free(line);

	return (token_array);
}
