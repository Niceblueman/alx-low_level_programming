#include <stdio.h>
#include "search_algos.h"

/**
 * jump_list - Search for a value in a sorted list using Jump search.
 * @list: Pointer to the head of the list to search in.
 * @size: Number of nodes in the list.
 * @value: Value to search for.
 * Return: Pointer to the first node where value is located,
 * or NULL if not found.
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step = 0;
	listint_t *current = list;
	listint_t *prev = NULL;

	if (list == NULL)
		return (NULL);

	while (step * step < size)
		step++;

	while (current != NULL && current->n < value)
	{
		prev = current;
		for (size_t i = 0; current->next && i < step; i++)
			current = current->next;
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
	}

	if (prev == NULL)
		return (NULL);
	printf(
	"Value found between indexes [%lu] and [%lu]\n",
	prev->index, current->index
	);

	while (prev != NULL && prev->n <= value)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}

	return (NULL);
}
