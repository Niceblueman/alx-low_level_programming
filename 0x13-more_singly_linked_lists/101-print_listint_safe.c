#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *curr = head, *prev;

	while (curr != NULL)
	{
		printf("[%p] %d\n", (void *)curr, curr->n);
		count++;
		prev = curr;
		curr = curr->next;
		if (curr >= prev) /* check for loop */
		{
			printf("-> [%p] %d\n", (void *)curr, curr->n);
			exit(98);
		}
	}

	return (count);
}
