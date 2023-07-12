#include "main.h"
#include <stdlib.h>

void convert(char **, char *);
void into_word(char **, char *, int, int, int);

/**
 * strtow - splits a string into words.
 * @str: the string
 *
 * Return: returns a pointer to an array of strings
 */
char **strtow(char *str)
{
	int i, _arg, len;
	char **words;

	if (str == NULL || str[0] == '\0' || (str[0] == ' ' && str[1] == '\0'))
		return (NULL);

	i = _arg = len = 0;
	while (str[i])
	{
	if (_arg == 0 && str[i] != ' ')
	{
	_arg = 1;
	}
	if (i > 0 && str[i] == ' ' && str[i - 1] != ' ')
	{
	_arg = 0;
	len++;
	}
	i++;
	}
	len += _arg == 1 ? 1 : 0;
	if (len == 0)
	{
	return (NULL);
	}
	words = (char **)malloc(sizeof(char *) * (len + 1));
	if (words == NULL)
	{
	return (NULL);
	}
	convert(words, str);
	words[len] = NULL;
	return (words);
}

/**
 * convert - a convert function for converting words to array
 * @words: the strings array
 * @str: the string
 */
void convert(char **words, char *str)
{
	int i, j, start, _arg;

	i = j = _arg = 0;
	while (str[i])
	{
		if (_arg == 0 && str[i] != ' ')
		{
			start = i;
			_arg = 1;
		}

		if (i > 0 && str[i] == ' ' && str[i - 1] != ' ')
		{
			into_word(words, str, start, i, j);
			j++;
			_arg = 0;
		}

		i++;
	}

	if (_arg == 1)
	{
	into_word(words, str, start, i, j);
	}
}

/**
 * into_word - creates a word and insert it into the array
 * @words: the string
 * @str: the string
 * @start: the starting index of the word
 * @end: the stopping index of the word
 * @index: the index of the array to insert the word
 */
void into_word(char **words, char *str, int start, int end, int index)
{
	int i, j;

	i = end - start;
	words[index] = (char *)malloc(sizeof(char) * (i + 1));

	for (j = 0; start < end; start++, j++)
	{
	words[index][j] = str[start];
	}
	words[index][j] = '\0';
}
