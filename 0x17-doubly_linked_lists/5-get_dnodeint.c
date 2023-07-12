#include "lists.h"

/**
 * get_dnodeint_at_index - Trouve un nœud spécifique
 * dans une liste chaînée.
 * @head: Pointeur vers le début de la liste.
 * @index: Index du nœud à récupérer.
 * Return: Pointeur vers le nœud indexé, ou NULL en cas d'échec.
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;

	if (head == NULL)
		return (NULL);
	if (index == 0)
		return (head);
	for (i = 0; i < index; i++)
	{
		if (head->next == NULL)
			return (NULL);
		head = head->next;
	}
	return (head);
}
