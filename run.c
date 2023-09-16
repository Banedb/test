#include "shell.h"
/**
 * cmdexe - calls in the execve function to enable command execution
 * @argv: Arguments passed to function
 * @envp: an array of pointers to strings
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
		if (cmd != NULL) /* fork only when command exists */
		{
			pid = fork();
			if (pid == 0)
			{
				exex = execve(cmd, argv, _env(envp));
				if (exex == -1)
				{
					write(STDERR_FILENO, "Do error.c\n", 11);
					free(cmd);
					exit(127);
				}
			}
			else if (pid == -1)
			{
				perror("Error");
				free(cmd);
				exit(EXIT_FAILURE);
			}
			else
				wait(NULL);
			free(cmd);
		}
		else if (_strcmp(argv[0], "exit") == 0)
		{
			free(cmd);
			exitShell();
		}
		else if (exex == -1)
		{
			write(STDERR_FILENO, "Do error.c", 10);
			free(cmd);
			return (-1);
		}
	}
	else
		return (-1);
	return (exex);
}
