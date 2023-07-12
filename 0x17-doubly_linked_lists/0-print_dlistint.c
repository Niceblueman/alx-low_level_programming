#include "lists.h"
#include <stdio.h>
#include "lists.h"
#include <stdio.h>

/**
* print_dlistint - Prints all the elements.
* @h: Pointer.
* Return: number of nodes.
*/
size_t print_dlistint(const dlistint_t *h)
{
	size_t node_count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		node_count++;
	}
	return (node_count);
}
