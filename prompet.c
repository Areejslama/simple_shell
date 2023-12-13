#include "shell.h"
/**
 * print- print the prompet
 *
 * Return:0 ALWAYS
*/
void print(void)
{

if (isatty(STDIN_FILENO))
{
write(STDIN_FILENO, "$ ", 2);
}
}
