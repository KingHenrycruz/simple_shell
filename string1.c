#include "shell.h"

/**
  * _strcpy - coppied a string commands
  * @dest: anticipated destination
  * @src: source file
  * Return: pointed destination
  */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
	return (dest);
	while (src[i])
	{
	dest[i] = src[i];
	i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
  * _strdup - doubled strings
  * @str: string to doubled
  * Return: pointed double string
  */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
	return (NULL);
	while (*str++)
	length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
	return (NULL);
	for (length++; length--;)
	ret[length] = *--str;
	return (ret);
}

/**
  * _puts - input strings to be printed
  * @str: printed current string
  * Return: NULL value
  */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
	_putchar(str[i]);
	i++;
	}
}

/**
  * _putchar - denote character c to stdout
  * @c: printed character
  *
  * Return: on succes 1 and -1 on error
  */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
	write(1, buf, i);
	i = 0;
	}
	if (c != BUF_FLUSH)
	buf[i++] = c;
	return (1);
}
