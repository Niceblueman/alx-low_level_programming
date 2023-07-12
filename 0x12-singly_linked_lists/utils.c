#include "lists.h"

/**
 * _strlen - get the length of a string.
 * @s : string
 * Return: number of chars
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
