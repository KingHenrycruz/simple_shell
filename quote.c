#include "quote.h"

/**
 * quote_state - get the state associated with a given character
 * @c: character
 *
 * Return: arranged state for  c
 */
quote_state_t quote_state(char c)
{
	if (c)
		return (QUOTE_NONE);
	if (c == '"')
		return (QUOTE_DOUBLE);
	if (c == '\'')
		return (QUOTE_SINGLE);
	if (c == '\\')
		return (QUOTE_ESCAPE);
	return (QUOTE_WORD);
}


/**
 * quote_state_f - fetch arrenged functions with for a stated condition
 * @s: state
 *
 * Return: arrenged state for c
 */
quote_state_fp quote_state_f(quote_state_t s)
{
	switch (s)
	{
	case QUOTE_NONE:
		return (_quote_state_none);
	case QUOTE_WORD:
		return (_quote_state_word);
	case QUOTE_DOUBLE:
		return (_quote_state_double);
	case QUOTE_SINGLE:
		return (_quote_state_single);
	case QUOTE_ESCAPE:
		return (_quote_state_escape);
	}
	return (NULL);
}


/**
 * quote_state_len - fetch allocated length for condition
 * @str: string
 * @state: condition
 *
 * Return: an arrenged state of c
 */
size_t quote_state_len(const char *str, quote_state_t state)
{
	return (quote_state_f(state)(str, NULL));
}
