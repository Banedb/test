#include "shell.h"
/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments passed to function
 * @envp: Array of environment variables
 *
 * Return: 0 (Success)
 */
int main(int argc, char **argv, char **envp)
{
	char *prompt = "$ ", *user_input;


	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		user_input = get_input();
		/* split input string and store as array */
		argv = tokenizer(user_input);
		cmdexe(argv, envp);
	}

	free(user_input);
	(void)argc;
	return (0);
}
