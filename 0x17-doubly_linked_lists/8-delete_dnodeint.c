#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Supprime un nœud à un index spécifique.
 * @head: Double pointeur vers la liste chaînée.
 * @index: Index auquel supprimer le nœud.
 *
 * Return: 1 en cas de succès, -1 en cas d'échec.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	dlistint_t *node_to_delete;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = current->next;
		if (current->next != NULL)
			current->next->prev = NULL;
		free(current);
		return (1);
	}

	for (i = 0; i < index - 1; i++)
	{
		if (current->next == NULL)
			return (-1);
		current = current->next;
	}

	if (current->next == NULL)
		return (-1);

	node_to_delete = current->next;
	current->next = node_to_delete->next;
	if (node_to_delete->next != NULL)
		node_to_delete->next->prev = current;
	free(node_to_delete);
	return (1);
}
