#include "main.h"
/**
 * print_binary - a function that prints the binary
 * representation of a number.
 * @n: int number
 * Return:  void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int i;
	int isprinted = 0;

	for (i = 0; i < (int)sizeof(unsigned long int) * 8; i++)
	{
		if (n & mask)
		{
			_putchar('1');
			isprinted = 1;
		}
		else
		{
			if (isprinted == 1 || i == ((int)sizeof(unsigned long int) * 8 - 1))
				_putchar('0');
		}
		mask >>= 1;
	}
}
