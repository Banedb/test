#include "shell.h"
/**
 * _which - finds path of command
 * @cmd: command
 * Return: path of command || NULL (Failure)
 */
char *_which(char *cmd)
{
	int len_cmd, len_dir;
	char *path = NULL, *path_copy = NULL, *cmdpath, *patht;
	struct stat buf;

	path = _getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		len_cmd = _strlen(cmd);
		patht = strtok(path_copy, ":");

		while (patht != NULL) /* build path for cmd */
		{
			len_dir = _strlen(patht);
			cmdpath = malloc(len_cmd + len_dir + 2);
			_strcpy(cmdpath, patht);
			_strcat(cmdpath, "/");
			_strcat(cmdpath, cmd);
			_strcat(cmdpath, "\0");

			if (stat(cmdpath, &buf) == 0)
			{
				free(path_copy);
				free(path);
				return (cmdpath);
			}
			else
			{
				free(cmdpath);
				patht = strtok(NULL, ":");
			}
		}
		free(path_copy);
		free(path);

		if (stat(cmd, &buf) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}

/**
 * _getenv - get enviroment viariables
 * @name: input str
 * Return: ..
 */
char *_getenv(const char *name)
{
	int i, j;
	char **envp = environ, *value, *value_start;
	size_t value_length;

	if (!name || !environ)
		return (NULL);
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; name[j] != '\0' && name[j] == envp[i][j]; j++)
		{
			/*compare chars until they differ or name[j] is '\0'*/
		}
		if (name[j] == '\0' && envp[i][j] == '=')
		{
			/* Found a matching environment variable*/
			value_start = &envp[i][j + 1];
			value_length = _strlen(value_start);

			value = malloc(value_length + 1);

			if (value)
			{
				_strcpy(value, value_start);
				return (value);
			}
		}
	}
	return (NULL); /* No matching env*/
}
