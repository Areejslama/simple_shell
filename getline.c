#include <shell.h>
/**
 * getline- delim the string
 *
 * Return:0 Always
*/
char _getline(void);
{
	char *line = NULL;
	size_t size = 0;

	if (isatty(STDOUT_FILENO))
	{
		write(STDOUT_FILENO, "$", 2);
	}
	if (getline(&line, &size, stdin)== -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
