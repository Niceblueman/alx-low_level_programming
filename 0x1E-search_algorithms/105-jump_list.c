#include "search_algos.h"

/**
 * jmp_list - Searches for an algorithm in a sorted singly
 *             linked list of integers using jmp search.
 * @list: A pointer to the  head of the linked list to search.
 * @size: The number of nodes in the list.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where the value is located.
 *
 * Description: Prints a value every time it is compared in the list.
 *              Uses the square root of the list size as the jmp step.
 */
listint_t *jmp_list(listint_t *list, size_t size, int value)
{
	size_t step, step_size;
	listint_t *node, *jmp;

	if (list == NULL || size == 0)
		return (NULL);

	step = 0;
	step_size = sqrt(size);
	for (node = jmp = list; jmp->index + 1 < size && jmp->n < value;)
	{
		node = jmp;
		for (step += step_size; jmp->index < step; jmp = jmp->next)
		{
			if (jmp->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jmp->index, jmp->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, jmp->index);

	for (; node->index < jmp->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
