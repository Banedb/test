#include "shell.h"

/**
 * _cd - custom implementation of cd
 * @path: ..
 *
 * Return: path to destination dir
 */
char *_cd(const char *path)
{
	char **envp, *env, currentPath[MAX_PATH_LENGTH], *prevDir;
	int i, j, envCount = 0;

	/* get number of environ variables */
	for (envp = environ; *envp != NULL; envp++, envCount++)
		;
	/* Populate the environment variables array */
	for (i = 0; i < envCount; i++, envp++)
	{
		env = *envp;
		j = 0;

		while (env[j] != '=')
			j++;
		if (!path)
		{
			if (_strcmp(_strndup(env, j), "HOME") == 0)
				return (env + j + 1);
		}
		else if (_strcmp(_strndup(env, j), "PWD") == 0)
			prevDir = env + j + 1;
	}
	if (_strcmp(_strdup(path), "-") == 0)
		path = prevDir;
	if (chdir(path) != 0)
	{
		_fprintf(stderr, "cd: Failed to change directory to %s\n", path);
		return (NULL);
	}
	if (getcwd(currentPath, sizeof(currentPath)) == NULL)
	{
		_fprintf(stderr, "cd: Failed to get current directory\n");
		return (NULL);
	}
	return (_strdup(path));
}

/**
 * _env - enviroment implementation
 * @envStrings: array of pointer to strings storing
 * environment variable and its values
 * Return: array of pointers to string, containing
 * environ variables and theri values.
 */

char **_env(char **envStrings)
{
	env_t *envs;
	int envCount = 0, i = 0, j;
	char **envp = environ, *env;

	/* get number of environ variables */
	for (; *envp != NULL; envp++)
		envCount++;
	envs = malloc(sizeof(struct env) * envCount);
	/* Populate the environment variables array */
	envp = environ;
	for ( ; i < envCount; i++)
	{
		env = *envp;
		j = 0;

		while (env[j] != '=')
			j++;
		envs[i].key = _strndup(env, j);
		envs[i].val = env + j + 1;
		envp++;
	}
	/* Store the environ variables in an array of pointers to strings */
	i = 0;
	while (*envp != NULL)
	{
		/*allocate mem for '=' and null terminator, hence + 2*/
		_puts(*envp);
		envp++;
	}
	/* set last element of array: NULL*/
	envStrings[envCount] = NULL;
	/* avoid mem leaks, free allocated mem*/
	for (i = 0; i < envCount; i++)
		free(envs[i].key);
	free(envs);

	return (envStrings);
}

/**
 * exitShell - exit cmd implementation
 */

void exitShell(void)
{
	exit(EXIT_SUCCESS);
}
