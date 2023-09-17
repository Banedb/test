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
	int exex = -1, status, exit_status;
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
					free(cmd);
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}
			else if (pid == -1)/* fork failed */
			{
				free(cmd);
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else
			{/* parent process */
				if (waitpid(pid, &status, 0) == -1)
				{
					free(cmd);
					perror("waitpid");
					exit(EXIT_FAILURE);
				}
				if (WIFEXITED(status))
				{
					exit_status = WEXITSTATUS(status);
					if (exit_status != 0)
						err_gen(argv, exit_status);
				}
				else if (WIFSIGNALED(status))
					write(2, "Command terminated by signal\n", 31);
				free(cmd);
			}
		}
		else if (_strcmp(argv[0], "exit") == 0)
			exitShell();
		else/* cannot locate exe */
			err_gen(argv, 127);
	}
	else
		return (exex);
	return (exex);
}
