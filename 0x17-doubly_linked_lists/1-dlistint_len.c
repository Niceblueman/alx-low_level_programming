#include "lists.h"

/**
 * dlistint_len - compte le nombre de nœuds dans
 * la liste chaînée
 * @h: pointeur vers le début de la liste chaînée
 * Return: le nombre de nœuds
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t i;

	for (i = 0; h != NULL; i++)
		h = h->next;
	return (i);
}
