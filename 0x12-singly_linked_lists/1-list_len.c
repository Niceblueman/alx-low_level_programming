#include "lists.h"

/**
 * list_len - a function that adds a new node at
 * the beginning of a list_t list
 * @h: list
 * Return: the address of the new element,
 * or NULL if it failed
 */
size_t list_len(const list_t *h)
{
	int i = 0;

	while (h)
	{
		i++;
		h = h->next;
	}
	return (i);
}
