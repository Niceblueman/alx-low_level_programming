#include "lists.h"

/**
 * free_listint_safe - frees a listint_t linked list safely
 * @h: pointer to the head of the list
 * Return: the size of the list that was free'd
 */

size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *curr = *h, *next;

	if (h == NULL || *h == NULL)
		return (count);
	while (curr != NULL)
	{
		next = curr->next;
		free(curr);
		count++;

		if (next >= curr) /* check for loop */
		{
			*h = NULL;
			return (count);
		}

		curr = next;
	}
	*h = NULL;

	return (count);
}
