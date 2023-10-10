#include <stdio.h>
#include "search_algos.h"

/**
 * my_binary_search - Search for a value in a sorted array using Binary search.
 * @array: Pointer to the first element of the array.
 * @left: Left bound of the search.
 * @right: Right bound of the search.
 * @value: Value to search for.
 * Return: Index where the value is located, or -1 if not found.
 */
int my_binary_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		printf("Searching in array: ");
		for (size_t i = left; i <= right; i++)
		{
			printf("%d", array[i]);
			if (i < right)
				printf(", ");
			else
				printf("\n");
		}

		if (array[mid] == value)
			return (mid);

		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return (-1);
}

/**
 * exponential_search - Search for a value in a sorted
 * array using Exponential search.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in the array.
 * @value: Value to search for.
 * Return: Index where the value is located, or -1 if not found.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t prev = 0;

	if (array == NULL || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		prev = bound;
		bound *= 2;
	}

	printf("Value found between indexes [%lu] and [%lu]\n", prev, bound);

	return (
	my_binary_search(
	array, prev,
	(bound < size - 1 ? bound : size - 1),
	value
	));
}
