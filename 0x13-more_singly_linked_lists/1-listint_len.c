#include "lists.h"

/**
 * listint_len - a function that returns the number
 * of elements in a linked listint_t list
 * @h: singly linked list
 * Return: size_t number of all elements.
 */
size_t listint_len(const listint_t *h)
{
size_t con = 0;
while (h != NULL)
{
h = h->next;
con++;
}
return (con);
}
