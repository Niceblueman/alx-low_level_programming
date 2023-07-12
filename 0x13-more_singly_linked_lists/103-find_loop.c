#include "lists.h"

/**
 * find_listint_loop - a function that finds the loop
 * in a linked list.
 * @head: singly linked list
 * Return: The address of the node where the loop starts
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *t, *h;

	if (head == NULL)
		return (NULL);

	t = h = head;
	while (h && h->next)
	{
		t = t->next;
		h = h->next->next;
		if (t == h)
		{
			t = head;
			while (t != h)
			{
				t = t->next;
				h = h->next;
			}
			return (h);
		}
	}
	return (NULL);
}
