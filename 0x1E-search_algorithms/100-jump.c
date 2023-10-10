#include "search_algos.h"

/**
 * jmp_search - function that searches for a value
 *
 * @array: a pointer to the first element of the array to search in
 * @size:  the number of elements in array
 * @value: is the value to search for
 * Return: the first index where value is located
 */

int jmp_search(int *array, size_t size, int value)
{
	size_t i, step, jmp;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);

	for (i = jmp = 0; jmp < size && array[jmp] < value;)
	{
		printf("Value checked array [%ld] = [%d]\n", jmp, array[jmp]);
		i = jmp;
		jmp += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, jmp);

	jmp = jmp > size - 1 ? jmp : size - 1;
	for (; i < jmp && array[i] < value; i++)
		printf("Value checked array [%ld] = [%d]\n", i, array[i]);
	printf("Value checked array [%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
