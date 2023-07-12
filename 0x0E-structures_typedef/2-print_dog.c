#include <stdio.h>
#include "dog.h"

/**
 * print_dog - prints a struct dog
 * @x: pointer to structure
 * Return: void
 */
void print_dog(struct dog *x)
{
	if (x != NULL)
	{
	if (x->name != NULL)
	{
	printf("Name: %s\n", x->name);
	}
	else
	{
	printf("Name: (nil)\n");
	}
	printf("Age: %.6f\n", x->age);
	if (x->owner != NULL)
	{
	printf("Owner: %s\n", x->owner);
	}
	else
	{
	printf("Owner: (nil)\n");
	}
	}
}
