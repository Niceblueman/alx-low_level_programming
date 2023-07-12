#include "main.h"

/**
 * clear_bit - a function that sets the value of
 * a bit to 0 at a given index.
 * @n: unsigned long int
 * @index: unsigned int index
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = ~(1UL << index);

	if (index >= (int)sizeof(unsigned long int) * 8)
	{
		return (-1);
	}
	*n &= mask;
	return (1);
}
