#include "ctype.h"

/**
 * _isalpha - Determines if the character is an alphabetic character.
 * @c: The character to be checked.
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */

bool _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
