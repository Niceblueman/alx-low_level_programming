#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Search for a value in a sorted array using Jump search.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 * Return: First index where value is located, or -1 if not found.
 */

int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t prev = 0;

	if (array == NULL)
		return (-1);
	printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
	while (array[min(step, size) - 1] < value)
	{
		prev = step;
		step += sqrt(size);
		if (prev >= size)
			return (-1);
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
	}
	while (array[prev] < value)
	{
		prev++;
		if (prev == min(step, size))
			return (-1);
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
	}
	if (array[prev] == value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		return (prev);
	}

	return (-1);
}
