#include "shell.h"
/**
 * freear- to free array
 * @ar:pointer to array
 * Return:0 Always
*/
void freear(char **ar)
{
int n;

if (!ar)
return;

for (n = 0; ar[n]; n++)
{
free(ar[n]);
ar[n] = NULL;
}
free(ar);
}
/**
 * print_prompet- to print a prompet
 *
 * Return:0 Always
*/
char *print_prompet(void)
{
char *line = NULL;
size_t size = 0;
ssize_t n;

if (isatty(STDIN_FILENO))
write(STDIN_FILENO, "$ ", 2);
n = getline(&line, &size, stdin);
if (n == -1)
{
free(line);
return (NULL);
}

return (line);
}
/**
 * token- to tokenaization a string
 * @line:char
 * Return:0 Always
*/
char **token(char *line)
{
char *b = NULL;
char *t = NULL;
char **arr = NULL;
int a;

if (!line)
return (NULL);

b = _strdup(line);
t = strtok(b, " \t\n");
if (t == NULL)
{
free(line);
free(b);
return (NULL);
}
for (a = 0; t; a++)
t = strtok(NULL, " \t\n");
free(b);
arr = malloc(sizeof(char *) * (a + 1));
if (!arr)
{
free(line);
return (NULL);
}
t = strtok(line, " \t\n");
for (a = 0; t; a++)
{
arr[a] = _strdup(t);
t = strtok(NULL, " \t\n");
}
free(line);
arr[a] = NULL;
return (arr);
}
/**
 * _myenv- get the environment
 * @p:char
 * Return:0 Always
*/
char *_myenv(char *p)
{
char *b, *k, *v, *e;
int n;

for (n = 0; env[n]; n++)
{
b = _strdup(env[n]);
k = strtok(b, "=");
if (_strcmp(k, p) == 0)
{
v = strtok(NULL, "\n");
e = _strdup(v);
free(b);
return (e);
}
free(b);
}
return (NULL);
}
/**
 * _handlepath- to handle the path
 * @cm:the path
 * Return:0 Always
*/
char *_handlepath(char *cm)
{
char *p_env, *c, *r;
int e;
struct stat at;

for (e = 0; cm[e]; e++)
{
if (cm[e] == '/')
{
if (stat(cm, &at) == 0)
return (_strdup(cm));
return (NULL);
}
}
p_env = _myenv("PATH");
if (!p_env)
return (NULL);
r = strtok(p_env, ":");
while (r)
{
c = malloc(_strlen(r) + _strlen(cm) + 2);
if (c)
{
_strcpy(c, r);
_strcat(c, "/");
_strcat(c, cm);
if (stat(c, &at) == 0)
{
free(p_env);
return (c);
}
free(c);
r = strtok(NULL, ":");
}
}
free(p_env);
return (NULL);
}
