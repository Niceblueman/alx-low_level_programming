/**
 * getlength - get the length of a string
 * @s: input string
 * Return: return the leng of the string
 * Author: @KM8Oz
 **/
int getlength(char *s)
{
if (*s == '\0')
{
return (0);
}
return (1 + getlength(s + 1));
}
/**
 * recursive_check - compare chars of mirrored indexes
 * @i: is the index
 * @l: is the length of the string
 * @s: is the string
 * Return: 1 if is polindrome or 0 if not
 **/
int recursive_check(int i, int l, char *s)
{
if (l > 0)
{
if (s[i] == s[l])
{
return (recursive_check(i + 1, l - 1, s));
}
else if (s[i] != s[l])
{
return (0);
}
else
{
return (1);
}
}
return (1);
}
/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: is the string
 * description: check if string respect palindromic structure (>>><<<)
 * Return: return 1 if the string is a palindrome or 0 otherwise
 **/
int is_palindrome(char *s)
{
return (recursive_check(0, getlength(s) - 1, s));
}
