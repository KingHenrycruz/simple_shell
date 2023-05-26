#include "quote.h"

/**
 * dequote - strings would be dequoted
 * @str: Dequoted string
 * Return: 1 if failure. 0 for success.
 */
char *dequote(const char *str)
{
	char *new;
	size_t len = 0, state_len;
	quote_state_t state;

	if (!str)
		return (NULL);

	new = malloc(sizeof(char) * (dequote_len(str) + 1));
	if (!new)
		return (NULL);

	while (*str)
	{
		state = quote_state(*str);
		str += (1 && (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE)));
		state_len = quote_state_len(str, state);
		if (state & QUOTE_DOUBLE)
		{
			for ( ; state_len; --state_len)
			{
				if (quote_state(*str++) & QUOTE_ESCAPE)
				{
					if (*str == '\n')
					{
						++str, --state_len;
						continue;
					}
					if (_isspecial_double(*str))
						++str, --state_len;
				}
				new[len++] = str[-1];
			}
		}
		_memcpy(new + len, str, state_len);
		len += state_len;
		str += state_len;
		str += (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)));
	}
	new[len] = '\0';
	return (new);
}

/**
 * dequote_len - String length after dequoting
 * @str: String for evaluation
 * Return: string length after dequoting
 */
size_t dequote_len(const char *str)
{
	size_t len = 0, state_len;
	quote_state_t state;

	while (*str)
	{
		state = quote_state(*str);
		str += (1 && (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE)));
		state_len = quote_state_len(str, state);
		if (state & QUOTE_DOUBLE)
		{
			for ( ; state_len; --state_len)
			{
				if (quote_state(*str++) & QUOTE_ESCAPE)
				{
					if (*str == '\n')
					{
						++str, --state_len;
						continue;
					}
					if (_isspecial_double(*str))
						++str, --state_len;
				}
				len++;
			}
		}
		len += state_len;
		str += state_len;
		str += (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)));
	}
	return (len);
}
