#include "ctype.h"

/**
 * _isalnum - alphanumeric char checker
 * @c: The character to be checked.
 * Return: 1 if the character is alphanumeric, 0 if otherwise.
 */

bool _isalnum(int c)
{
	return (_isdigit(c) || _isalpha(c));
}
