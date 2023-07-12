#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * str_concat - concatenates two strings.
 * @s1: first string
 * @s2: second string
 *
 * Return: a pointer to a newly allocated space in memory which
 * contains the contents of s1, followed by the contents of s2,
 * and null terminated. NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	int i, j, l1 = 0, l2 = 0, l;
	char *result;

	if (s1 != NULL)
	{
	i = 0;
	while (s1[i++] != '\0')
	{
	l1++;
	}
	}
	if (s2 != NULL)
	{
	i = 0;
	while (s2[i++] != '\0')
	{
	l2++;
	}
	}
	l = l1 + l2;
	result = (char *)malloc(sizeof(char) * (l + 1));
	if (result == NULL)
	{
	return (NULL);
	}
	for (i = 0; i < l1; i++)
	{
	result[i] = s1[i];
	}
	for (j = 0; j < l2; j++, i++)
	{
	result[i] = s2[j];
	}
	result[l] = '\0';

	return (result);
}
