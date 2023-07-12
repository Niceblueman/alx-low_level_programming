/**
 * factorial - a function that finds the factorial of *n
 * Author: @KM8Oz
 * @n: positive number
 * Return: factorial of @n
*/
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}
