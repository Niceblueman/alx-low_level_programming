#include "lists.h"
/**
 * add_nodeint_end - a function that adds a new
 * node at the beginning of a listint_t list.
 * @head: head of double pointer
 * @n: value
 * Return: NULL if it failed
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *swap;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	swap = *head;
	while (1)
	{
	if (swap->next == NULL)
	{
	swap->next = new;
	break;
	}
	swap = swap->next;
	}
	return (new);
}
