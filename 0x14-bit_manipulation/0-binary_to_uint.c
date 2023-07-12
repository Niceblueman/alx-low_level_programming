#include "main.h"

/**
 * binary_to_uint - a function that converts a binary
 * number to an unsigned int.
 * @b: pointing to a binary number string
 *
 * Return:converted number, or 0
 */
unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	unsigned int result;

	result = 0;
	if (!b)
		return (0);
	while (b[i] != '\0')
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (b[i] != '\0')
	{
		result <<= 1;
		if (b[i] == '1')
			result += 1;
		i++;
	}
	return (result);
}
