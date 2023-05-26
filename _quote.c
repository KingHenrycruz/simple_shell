#include "quote.h"

/**
 * _quote_state_none - length of all it's states
 * @str: represents all strings
 * @state: The string's state
 *
 * Return: Maybe not int val but length  state
 */
size_t _quote_state_none(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (_isspace(*str))
		++str, ++len;
	if (state && *str)
		*state = quote_state(*str);
	return (len);
}


/**
 * _quote_state_word - length of all it's stat
 * @str: represents all strings
 * @state: The string's statee
 *
 * Return:  Maybe not int val but length  state
 */
size_t _quote_state_word(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && !_isspace(*str) && !_isquote(*str))
		++str, ++len;
	if (state && *str)
		*state = quote_state(*str);
	return (len);
}


/**
 * _quote_state_double - length of all it's state
 * @str: represents all strings
 * @state: The string's state
 * Return:  Maybe not int val but length  state
 */
size_t _quote_state_double(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && *str != '"')
		++str, ++len;
	if (state && *str)
		*state = quote_state(*(str + 1));
	return (len);
}


/**
 * _quote_state_single - length of all it's state
 * @str: represents all strings
 * @state: The string's state
 * Return:  Maybe not int val but length  state
 */
size_t _quote_state_single(const char *str, quote_state_t *state)
{
	size_t len = 0;

	while (*str && *str != '\'')
		++str, ++len;
	if (state && *str)
		*state = quote_state(*(str + 1));
	return (len);
}


/**
 * _quote_state_escape - length of all it's state
 * @str: represents all strings
 * @state: The string's state
 * Return:  Maybe not int val but length  state
 */
size_t _quote_state_escape(const char *str, quote_state_t *state)
{
	if (*str)
	{
		if (state && *(++str))
			*state = quote_state(*str);
		return (1);
	}
	return (0);
}
