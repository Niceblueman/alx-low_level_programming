#include "function_pointers.h"

/**
  * int_index - function that searches for an
  * integer
  * @array: array of elements
  * @size: number of elemts in the array
  * @cmp: a pointer to the function to be
  * used to compare values
  * Return: the index of the first element for
  * which the cmp function does not return 0
  */
int int_index(int *array, int size, int (*cmp)(int))
{
	int x = 0;

	if (size > 0)
	{
		if (array != NULL && cmp != NULL)
		{
			while (x < size)
			{
				if (cmp(array[x]))
				{
					return (x);
				}
				x++;
			}
		}
	}

	return (-1);
}
