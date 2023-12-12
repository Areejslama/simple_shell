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
	size_t g;

	if (isatty(STDIN_FILENO) == 1)
	{
		  write(STDIN_FILENO, "$ ", 2);
	}
	g = getline(&line, &size, stdin);
	if (g == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
