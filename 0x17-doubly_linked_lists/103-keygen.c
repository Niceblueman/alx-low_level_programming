#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * generateKey - generate a key for username
 * @username: the username
 * Return: Void
 */
void generateKey(char *username)
{
	unsigned int i, b;
	size_t len, add;
	char *l = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	char p[7] = "      ";

	len = strlen(username);
	p[0] = l[(len ^ 59) & 63];
	for (i = 0, add = 0; i < len; i++)
		add += username[i];
	p[1] = l[(add ^ 79) & 63];
	for (i = 0, b = 1; i < len; i++)
		b *= username[i];
	p[2] = l[(b ^ 85) & 63];
	for (b = username[0], i = 0; i < len; i++)
		if ((char)b <= username[i])
			b = username[i];
	srand(b ^ 14);
	p[3] = l[rand() & 63];
	for (b = 0, i = 0; i < len; i++)
		b += username[i] * username[i];
	p[4] = l[(b ^ 239) & 63];
	for (b = 0, i = 0; (char)i < username[0]; i++)
		b = rand();
	p[5] = l[(b ^ 229) & 63];

	printf("%s\n", p);
}

/**
 * main - entry point
 * @argc: arguments count
 * @argv: arguments list
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	char *username;

	if (argc != 2)
	{
		printf("Correct usage: ./keygen5 username\n");
		return (1);
	}

	username = argv[1];
	generateKey(username);

	return (0);
}
