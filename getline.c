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
		  _putchar("#cisfun$ ");
	}
	g = getline(&line, &size, stdin);
	if (g == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
