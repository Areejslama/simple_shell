#include "shell.h"
/**
 * print_command- print the prompet
 *
 * Return:0 ALWAYS
*/
char *print_command(void)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t p;

	if (isatty(STDIN_FILENO))
	p = getline(&line, &size, stdin);
	if (p == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
