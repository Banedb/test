#include "shell.h"

/**
 * _cd - custom implementation of cd
 * @path: ..
 *
 * Return: path to destination dir
 */
char *_cd(const char *path)
{
	char **envp, *env, currentPath[MAXPATH_LEN];
	char *prevDir, *pathcopy, *envcopy;
	int i, j, envCount = 0;

	/* get number of environ variables */
	for (envp = environ; *envp != NULL; envp++, envCount++)
		;
	/* Populate the environment variables array */
	for (i = 0, envp = environ; i < envCount; i++, envp++)
	{
		env = *envp;
		j = 0;

		while (env[j] != '=')
			j++;
		envcopy = _strndup(env, j);
		if (!path)
		{
			if (_strcmp(envcopy, "HOME") == 0)
			{
				if (envcopy)
					free(envcopy);
				return (env + j + 1);
			}
		}
		else if (_strcmp(envcopy, "PWD") == 0)
			prevDir = env + j + 1;
		if (envcopy)
			free(envcopy);
	}
	pathcopy = _strdup(path);
	if (_strcmp(pathcopy, "-") == 0)
		path = prevDir;
	if (chdir(path) != 0)
	{
		cd_error(pathcopy);
		if (pathcopy)
			free(pathcopy);
		return (NULL);
	}
	if (getcwd(currentPath, sizeof(currentPath)) == NULL)
	{
		write(2, "cd : error retrieving current directory\n", 42);
		if (pathcopy)
			free(pathcopy);
		return (NULL);
	}
	return (pathcopy);
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
