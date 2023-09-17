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
	char *prompt = "$ ", *user_input = NULL;

	name = argv[0];
	hist = 0;
	if (signal(SIGINT, sig_h) == SIG_ERR)
		exit(EXIT_FAILURE);

	/* Interactive mode: */
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			hist++;
			write(STDOUT_FILENO, prompt, 2);
			fflush(stdout);
			user_input = get_input();
			/* split input string and store as array */
			argv = tokenizer(user_input);
			cmdexe(argv, envp);
			free(argv);
		}
		if (!user_input)
			free(user_input);
	}
	else
	{
		/* Non-interactive mode: */
		if (argc > 1)
		{
			argv = tokenizer(argv[1]);
			cmdexe(argv, envp);
			free(argv);
			return (0);
		}
	}
	return (0);
}
