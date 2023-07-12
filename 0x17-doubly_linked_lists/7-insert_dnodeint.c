#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_dnodeint_at_index - Insère un nouveau
 * nœud à une position donnée.
 * @h: Double pointeur vers le début de la liste chaînée.
 * @idx: Index auquel insérer le nouveau nœud.
 * @n: Données à insérer dans le nouveau nœud.
 *
 * Return: Pointeur vers le nouveau nœud,
 * ou NULL en cas d'échec.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *current = *h;
	unsigned int i;

	if (h == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	if (idx == 0)
	{
		new->next = *h;
		if (*h != NULL)
			(*h)->prev = new;
		*h = new;
	}
	else
	{
		for (i = 0; i < idx - 1; i++)
		{
			if (current == NULL)
			{
				free(new);
				return (NULL);
			}
			current = current->next;
		}
		if (current == NULL)
		{
			free(new);
			return (NULL);
		}
		new->next = current->next;
		if (current->next != NULL)
			current->next->prev = new;
		current->next = new;
		new->prev = current;
	}
	return (new);
}
