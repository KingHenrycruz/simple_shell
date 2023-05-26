#include "ctype.h"

/**
 * _isspace - identify whitespaced charactes.
 * @c: identified charater
 * Return: Could c be whitespaced, return 1. Otherwise, return 0.
 */
bool _isspace(int c)
{
	return (c == ' ' || (c >= 0x09 && c <= 0x0d));
}
