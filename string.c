#include "shell.h"

/**
  * _strlen - returned stranght values of a string
  * @s: string values to be analyzed
  * Return: interger values of string
  */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
	i++;
	return (i);
}

/**
  * _strcmp - execute incorrect analyzing of two strings.
  * @s1: begining string
  * @s2: secondary string
  * Return: negative if s1 < s2, positive if s1 > s2, 0 if s1 == s2
  */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && s2)
	{
	if (*s1 != *s2)
	return (*s1 - *s2);
	s1++;
	s2++;
	}
	if (*s1 == *s2)
	return (0);
	else
	return (*s1 < *s2 ? -1 : 1);
}

/**
  * starts_with - review needle starts by haystack
  * @haystack: string to be identiied
  * @needle: the substring to be identified
  * Return:  the location for preceding char of haystack or NULL
  */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
	if (*needle++ != *haystack++)
	return (NULL);
	return ((char *)haystack);
}

/**
  * _strcat - intergrated double strings
  * @dest: buffer station
  * @src: buffer origin
  * Return: pointed buffer station
  */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
	dest++;
	while (*src)
	*dest++ = *src++;
	*dest = *src;
	return (ret);
}
