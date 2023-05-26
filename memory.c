#include "shell.h"
/**
  *bfree - free pointed and voids position
  * @ptr: position pointed to free
  * Return: 1 if loosened, otherwise 0.
  */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
	free(*ptr);
	*ptr = NULL;
	return (1);
	}
	return (0);
}
