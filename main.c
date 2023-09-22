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
	int exit_status;

	prompt = "$ ";
	name = argv[0];
	if (signal(SIGINT, sig_h) == SIG_ERR)
		exit(EXIT_FAILURE);

	/* Interactive mode: */
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(STDOUT_FILENO, prompt, 2);
			fflush(stdout);
			exit_status = run_input();
		}
	}
	else
	{/* Non-interactive mode: */
		exit_status = run_input();
		return (exit_status);
	}
	(void)argc;
	return (exit_status);
}
