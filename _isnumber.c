#include "ctype.h"

/**
  * _isnumber - Determines if a string contains only digits
  * @s: string as a pointer
  * Return: 1 if the character is a digit, 0 otherwise. 
  */
bool _isnumber(const char *s)
{
	if (s)
	{
		while (*s)
		{
			if (!_isdigit(*s++))
				return (false);
		}
		return (true);
	}
	return (false);
}
