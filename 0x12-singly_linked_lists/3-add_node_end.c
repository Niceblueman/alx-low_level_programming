#include "lists.h"

/**
 * add_node_end - a function that adds a new_element
 * node at the end of a list_t list.
 * @head: double pointer to a linked list
 * @str: str value
 *
 * Return: the address of the new_element element,
 * or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_element, *old_element;

	new_element = malloc(sizeof(list_t));
	if (new_element == NULL)
		return (NULL);
	if (str == NULL)
		return (NULL);
	new_element->str = strdup(str);
	if (new_element->str == NULL)
	{
		free(new_element);
		return (NULL);
	}
	new_element->len = (int)strlen(new_element->str);
	new_element->next = NULL;
	if (*head == NULL)
	{
		*head = new_element;
		return (new_element);
	}
	old_element = *head;
	while (old_element->next)
		old_element = old_element->next;
	old_element->next = new_element;
	return (new_element);
}
