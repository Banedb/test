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
	char *prompt = "$ ", *user_input = NULL, **args;
	int i;
	bool ch;

	name = argv[0];
	hist = 0;
	if (signal(SIGINT, sig_h) == SIG_ERR)
		exit(EXIT_FAILURE);

	/* Interactive mode: */
	ch = (isatty(STDIN_FILENO));
	printf("Bool ch is %d\n", ch);
	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			hist++;
			printf("IM1 argc is %d and argv[0]is %s and argv[1]is %s\n", argc, argv[0], argv[1]);
			write(STDOUT_FILENO, prompt, 2);
			fflush(stdout);
			user_input = get_input();
			/* split input string and store as array */
			args = tokenizer(user_input);
			cmdexe(args, envp);
			printf("IM2 argc is %d and args[0]is %s and args[1]is %s\n", argc, args[0], args[1]);
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			if (args)
				free(args);
		}
		if (user_input)
			free(user_input);
	}
	else
	{/* Non-interactive mode: */
		printf("NIM1 argc is %d and argv[0]is %s and argv[1]is %s\n", argc, argv[0], argv[1]);
		args = tokenizer(argv[1]);
		cmdexe(args, envp);
		printf("NIM2 argc is %d and args[0]is %s and args[1]is %s\n", argc, args[0], args[1]);
		free(args);
		return (0);
	}
	return (0);
}
