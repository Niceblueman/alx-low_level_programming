#include "main.h"
/**
 * flip_bits - function that returns the number
 * of bits you would need to flip
 * to get from one number to another
 * @n: first int
 * @m: second int
 * Return: the number of bits you would need to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor = n ^ m;
	unsigned int count = 0;

	while (xor)
	{
		count += xor & 1;
		xor >>= 1;
	}
	return (count);
}
