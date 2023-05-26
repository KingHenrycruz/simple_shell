#include "ctype.h"

/**
  * _isident - checks if the character is an identifier character
  * @c: The character to be checked.
  * Return: 1 if the character is alphabetic, 0 otherwise.
  */
bool _isident(int c)
{
	return (c == '_' || _isalnum(c));
}
