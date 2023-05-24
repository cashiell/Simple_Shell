#incluude "shell.h"

/**
 * check_path - check if command is in the path directories
 * @string: an array of strings
 * @envp: environment variables
 * Return: pointer to a linked list
 */
void check_path(char **string, char **envp)
{
	char *str1, *str2, *path;
	int start, end, i;

	str1 = str_concat("/", string[0]);
	path = _getenv("PATH", envp);
	if (path == NULL)
	{
		free(str1);
		exit(0);
	}
	start = last = i = 0;
	while (path[i])
	{
		if (path[i] == ':' || path[i + 1] == '\0')
		{
			if (path[i + 1] == '\0')
			{
				i += 1;
				last = 1;
			}
			else
				path[i] = '\0';
			str2 = str_concat(path + start, str1);
			if (access(str2, F_OK) == 0)
			{
				free(string[0]);
				string[0] = str2;
				free(str1);
				return;
			}
			free(str2);
			if (last)
				break;
			path[i] = ':';
			start = i + 1;
		}
		i += 1;
	}
	free(str1);
}
