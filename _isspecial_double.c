#include "quote.h"

/**
 * _isspecial_double - identify special characters in two quotes
 * @c: identified character.
 * Return:  return 1. Otherwise, return 0 if c is a character
 */
int _isspecial_double(char c)
{
	return (c == '"' || c == '$' || c == '\\');
}
