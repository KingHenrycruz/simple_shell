#include "string.h"

/**
 * _memchr - Index of first matching value
 * @src: Memory area source
 * @n: Numeric size of search area
 * @chr: Char to be found
 * Return: If chr does not occur in the first n elements of src, return -1.
 */

ssize_t _memchr(const void *src, unsigned char chr, size_t n)
{
	const unsigned char *mem = src;
	ssize_t i = 0;

	if (src)
	{
		while (n--)
		{
			if (mem[i] == chr)
				return (i);
			i += 1;
		}
	}
	return (-1);
}

/**
 * _memcpy - Memory area to copy
 * @dest: Pointer to target area
 * @src: Pointer to source area
 * @n: Number of bytes to be copiedcopy
 *
 * Description: Copies bytes from the memory area at src to dest
 * Return: As pointer to dest
 */
void *_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *w_pos = dest;
	const unsigned char *r_pos = src;

	if (dest && src)
	{
		while (n--)
			*w_pos++ = *r_pos++;
	}
	return (dest);
}

/**
 * _memdup - Memory area to duplicate
 * @src: Pointer to source area
 * @n: Number of bytes to duplicated
 * Return: If memory allocation fails, return NULL.
*/
void *_memdup(const void *src, size_t n)
{
	void *dup = malloc(n);
	unsigned char *w_pos = dup;
	const unsigned char *r_pos = src;

	if (dup)
	{
		while (n--)
			*w_pos++ = *r_pos++;
	}
	return (dup);
}

/**
 * _memset - Fill memory region with set value
 * @dest: Pointer region src
 * @chr: Character to be written to region
 * @n: Bytes to be written
 * Return: destination value
 */
void *_memset(void *dest, unsigned char chr, size_t n)
{
	unsigned char *mem = dest;

	if (dest)
	{
		while (n--)
			*mem++ = chr;
	}
	return (dest);
}

