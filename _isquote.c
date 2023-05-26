#include "ctype.h"

/**
 * _isquote - identify qoute characters
 * @c: checked commands
 * Return:  return 1. Otherwise, return 0. if c is qouted
 */
bool _isquote(int c)
{
	return (c == '"' || c == '\'' || c == '\\');
}
