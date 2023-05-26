#include "ctype.h"

/**
  * _isdigit - Determines if the character is digit
  * @c: The character to be checked.
  * Return: 1 if the character is a digit, 0 otherwise.
  */
bool _isdigit(int c)
{
	return (c <= '9' && c >= '0');
}
