#include "main.h"

/**
 * interact - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interact(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_dlm - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_dlm(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_isalp - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalp(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sgn = 1, flg = 0, outp;
	unsigned int res = 0;

	for (i = 0;  s[i] != '\0' && flg != 2; i++)
	{
		if (s[i] == '-')
			sgn *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flg = 1;
			res *= 10;
			res += (s[i] - '0');
		}
		else if (flg == 1)
			flg = 2;
	}

	if (sgn == -1)
		outp = -res;
	else
		outp = res;

	return (outp);
}
