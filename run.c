#include "shell.h"
/**
 * cmdexe - calls in the execve function to enable command execution
 * @argv: Arguments passed to function
 * @envp: an array of pointers to strings,
 * storing environment varibles and their values
 * Return: 0 (Success)
 */
int cmdexe(char **argv, char **envp)
{
	char *cmd = NULL;
	int exex = -1;
	pid_t pid;

	if (argv && argv[0])
	{
		cmd = _which(argv[0]);
		/* To fork only when command exists */
		if (cmd != NULL)
		{
			pid = fork();
			if (pid == 0)
			{
				exex = execve(cmd, argv, _env(envp));
				if (exex == -1)
				{
					write(STDERR_FILENO, "Do error.c", 10);
					exit(127);
				}
			}
			else if (pid == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			else
				wait(NULL);
		}
		else if (_strcmp(argv[0], "exit") == 0)
			exitShell();
		else if (exex == -1)
		{
			write(STDERR_FILENO, "Do error.c", 10);
			return (-1);
		}
	}
	else
		return (-1);
	return (exex);
}
