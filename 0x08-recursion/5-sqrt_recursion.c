/**
 * sqrt_recursive - a function that does the recursion
 *                      in binary thre method
 * Author: @KM8Oz
 * @num : input number
 * @start: minimum number
 * @end: maximum number
 *
 * Return: square root of @n or -1
 */
int sqrt_recursive(int num, int start, int end)
{
	float mid = (((float)start + (float)end) / 2);
	float guess_root = ((float)num / (int)mid);

	if (start == end)
	{
	return (-1);
	}
	if ((guess_root * guess_root) == num)
	{
	return ((int)guess_root);
	}
	else if (guess_root > mid)
	{
	return (sqrt_recursive(num, mid + 1, end));
	}
	else
	{
	return (sqrt_recursive(num, start, mid));
	}
}

/**
 * _sqrt_recursion - a function that returns the
 *                   square root of input number
 *
 * @n: input number
 *
 * Return: square root
 */
int _sqrt_recursion(int n)
{
	if (n == 1)
		return (1);
	else if (n == 0)
		return (0);
	else if (n < 0)
		return (-1);
	else
		return (sqrt_recursive(n, 1, n));
}
