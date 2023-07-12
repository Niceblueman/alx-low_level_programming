#include "main.h"

/**
 * get_bit - a function that returns the value
 * of a bit at a given index.
 * @n: bits
 * @index: is the index
 * Return: 0 or 1 or -1
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1UL << index;

	if (index >= (int)sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	if (n & mask)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
