#include <shell.h>
/**
 * main- this is entry point
 * @argc:argu count
 * @argv:argu vector
 * Return:0 Always
*/
int main(int argc, char *argv[])
{
	char *n;
	char *line = NULL;
	size_t size = 0;
	ssize_t g = 0;

	(void) argc;
	n = argv[0];

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDIN_FILENO, "$ ", 2);
		g = getline(&line, &size, stdin);
		if (g == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(STDIN_FILENO, "\n", 1);
			break;
		}

		if (line[g - 1]  == '\n')
			line[g - 1]  = '\0';
		if (*line == '\0')
			continue;
	}
	free(line);
	line = NULL;
	return (0);
