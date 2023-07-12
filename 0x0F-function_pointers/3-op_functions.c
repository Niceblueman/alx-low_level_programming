#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * op_add - add two numbers
  * @a: first number
  * @b: second number
  *
  * Return: the result of the addition
  */
int op_add(int a, int b)
{
	return (a + b);
}

/**
  * op_sub - substract two numbers
  * @a: first number
  * @b: second number
  *
  * Return: the result of the substraction
  */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
  * op_mul - multiply two numbers
  * @a: first number
  * @b: second number
  *
  * Return: the result of the multiplication
  */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
  * op_div - divide two numbers
  * @a: first number
  * @b: second number
  *
  * Return: the result of the division
  */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a / b);
}

/**
  * op_mod - module two numbers
  * @a: first number
  * @b: second number
  *
  * Return: the result of the module
  */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	return (a % b);
}
