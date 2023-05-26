#include "string.h"

/**
  * _strnchr - review first matching character index
  * @str: string output
  * @chr: character output
  * @n: maximum limit of characters checked
  * Return: first charexter appearance, or -1 chr is not found
  */
ssize_t _strnchr(const char *str, char chr, size_t n)
{
	ssize_t index;

	if (!str)
		return (-1);

	for (index = 0; n && str[index]; --n, ++index)
	{
		if (str[index] == chr)
			return (index);
	}

	return (-1);
}


/**
 * _strndup - duplicated string output
 * @str: doubled string
 * @n: maximum bytes coppied
 *
 * Description: function maximum capacit is n bytes. If str is longer
 * than n, n bytes are copied only, and the terminated byte is added.
 *
 * Return: If str is void or allocated memory is void, return void.
 * Otherwise a return a double changing allocation
 */
char *_strndup(const char *str, size_t n)
{
	char *dup;
	size_t len = 0;

	if (!str)
		return (NULL);

	while (n && str[len])
		--n, ++len;

	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);

	dup[len] = '\0';

	while (len--)
		dup[len] = str[len];

	return (dup);
}


/**
 * _strnlen - compute the string length
 * @str: a measured string
 * @n:maximum checked characters
 * Return: the lesser of n and the length of the string
 */
ssize_t _strnlen(const char *str, size_t n)
{
	const char *pos = str;

	if (!str)
		return (-1);

	while (n && *pos)
		--n, ++pos;

	return (pos - str);
}



/**
 * _strncmp - double strings compared
 * @s1: first compared string
 * @s2: second compared string
 * @n: the maximum compared bytes
 * Return: 0 if s1 matches s2,
 * otherwise int below 0 if s1 is below s2,
 * otherwise int above 0 if s1 is above s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	for (; n && *s1 && *s2; --n, ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}

	if (n)
	{
		if (*s1)
			return (1);
		if (*s2)
			return (-1);
	}

	return (0);
}


/**
 * _strncpy - coppied string
 * @dest: destination
 * @src: source file
 * @n:the maximum coppied bytes
 *
 * Description: function capable to copy n bytes from src to dest.
 *
 * Return: pointed dest
 */

char *_strncpy(char *dest, const char *src, size_t n)
{
	char *pos = dest;

	for ( ; n && *src; --n)
		*pos++ = *src++;
	if (n)
		*pos = '\0';

	return (dest);
}
