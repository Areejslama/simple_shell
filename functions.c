#include "shell.h"
/**
 * _strcpy- function that copies the string pointed
 * @dest:parameter
 * @src:parameter
 *
 * Return:the pointer to dust
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0' ; i++)
	{
		dest[i] = src[i];
	}
		dest[i] = '\0';
		return (dest);
}
/**
 * _strlen- return the length of string
 * @s:parameter
 *
 * Return:length of string
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _strcat- function that concatenates two strings
 * @dest:string to be cat
 * @src:string to be cat
 *
 * Return:pointer to string
*/
char *_strcat(char *dest, char *src)
{
	int i;

	int dest_len = 0;
	int src_len = 0;

	for (i = 0 ; dest[i] != '\0' ; i++)
		dest_len++;
	for (i = 0 ; src[i] != '\0' ; i++)
		src_len++;
	for (i = 0 ; i <= src_len ; i++)
		dest[dest_len + i] = src[i];
	return (dest);
}
/**
 *  _strcmp- compares two strings
 *  @s1:string to be compared
 *  @s2:string to be compared
 *
 *  Return:0 Always (success)
*/
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
			i++;
		}
		return (0);
}
/**
 *  _strdup- returns a pointer to a newly allocated space in memory
 *@str:parameter
 *  Return:NULL
*/
char *_strdup(char *str)
{
	char *copy;
	int len;

	if (str == NULL)
	{
		return (NULL);
	}
	for (len = 0 ; str[len] != '\0' ; len++)
		len++;

	copy = malloc((sizeof(char) * len) + 1);
	if (copy == NULL)
	{
		return (NULL);
	}
	for (len = 0 ; str[len] != '\0' ; len++)
	copy[len] = str[len];
	return (copy);
}
