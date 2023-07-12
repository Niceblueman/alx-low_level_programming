#include <stdio.h>

int isPalindrome(int num)
{
	int original = num;
	int reversed = 0;

	while (num > 0)
	{
		reversed = reversed * 10 + num % 10;
		num /= 10;
	}

	return (original == reversed);
}

int main(void)
{
	int largestPalindrome = 0;
	int product, i, j;
	FILE *file;

	for (i = 100; i <= 999; i++)
	{
		for (j = 100; j <= 999; j++)
		{
			product = i * j;
			if (isPalindrome(product) && product > largestPalindrome)
			{
				largestPalindrome = product;
			}
		}
	}
	file = fopen("102-result", "w");
	fprintf(file, "%d", largestPalindrome);
	fclose(file);

	return (0);
}
