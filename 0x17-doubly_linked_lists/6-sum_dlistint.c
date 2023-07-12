#include "lists.h"

/**
 * sum_dlistint - Calcule la somme de toutes les données
 * d'une liste chaînée dlistint_t.
 * @head: Pointeur vers le début de la liste chaînée.
 * Return: Somme de toutes les données, ou 0 si la liste est vide.
 */

int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
