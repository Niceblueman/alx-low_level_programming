#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - Libère une liste dlistint_t.
 * @head: Pointeur vers le début de la liste chaînée.
 * Return : void
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
