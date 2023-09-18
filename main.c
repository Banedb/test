#include "shell.h"
/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments passed to function
 *
 * Return: 0 (Success)
 */
int main(int argc, char **argv)
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
			user_input = run_input();
		}
		if (user_input)
			free(user_input);
	}
	else
	{/* Non-interactive mode: */
		user_input = run_input();
		return (0);
	}
	(void)argc;
	return (0);
}
