#include "tokens.h"

/**
 * tokenize - string into words/tokens
 * @str: evaluated string
 * Return: NULL if malloc fails or string is 0.
 */
char **tokenize(const char *str)
{
	char **tokens;
	const char *tok;
	size_t count;
	quote_state_t state;

	if (!str)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count_tokens(str) + 1));
	if (!tokens)
		return (NULL);

	for (count = 0; *(str += quote_state_len(str, QUOTE_NONE)); ++count)
	{
		tok = str;

		while (*str && (state = quote_state(*str)) != QUOTE_NONE)
		{
			if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
				str += quote_state_len(str + 1, state) + 1;
			else
				str += quote_state_len(str, state);

			if (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)))
				++str;
		}

		tokens[count] = _memdup(tok, str - tok + 1);
		if (!tokens[count])
		{
			free_tokens(&tokens);
			return (NULL);
		}
		tokens[count][str - tok] = '\0';
	}
	tokens[count] = NULL;

	return (tokens);
}


/**
 * count_tokens - compute the length of a string after dequoting
 * @str: evaluated string
 * Return: string length
 */
size_t count_tokens(const char *str)
{
	size_t count;
	quote_state_t state;

	for (count = 0; *(str += quote_state_len(str, QUOTE_NONE)); ++count)
	{
		while (*str && (state = quote_state(*str)) != QUOTE_NONE)
		{
			if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
				str += quote_state_len(str + 1, state) + 1;
			else
				str += quote_state_len(str, state);

			if (*str && (state & (QUOTE_DOUBLE | QUOTE_SINGLE)))
				++str;
		}
	}
	return (count);
}


/**
 * tokenize_noquote - make a tokens from string
 * @str: tokenized string
 * Return: 0 if malloc fails
 */
char **tokenize_noquote(const char *str)
{
	char **tokens;
	const char *tok;
	size_t count;

	if (!str)
		return (NULL);

	tokens = malloc(sizeof(char *) * (count_tokens_noquote(str) + 1));
	if (!tokens)
		return (NULL);

	for (count = 0; *str; ++count)
	{
		while (_isspace(*str))
			++str;
		if (!*str)
			break;

		tok = str;
		do {
			++str;
		} while (*str && !_isspace(*str));

		tokens[count] = _memdup(tok, str - tok + 1);
		if (!tokens[count])
		{
			free_tokens(&tokens);
			return (NULL);
		}
		tokens[count][str - tok] = '\0';
	}
	tokens[count] = NULL;

	return (tokens);
}


/**
 * count_tokens_noquote - for counting words of a string
 * @str: strings meant for evaluation
 * Return: the number of words, if NULL, then returns -1
 */
size_t count_tokens_noquote(const char *str)
{
	size_t tok_count;

	for (tok_count = 0; *str; ++tok_count)
	{
		while (_isspace(*str))
			++str;
		if (!*str)
			break;
		do {
			++str;
		} while (*str && !_isspace(*str));
	}
	return (tok_count);
}


/**
 * free_tokens - nullifying and freeing an array of strings
 * @tokens: points to the token arrays.
 */
void free_tokens(char ***tokens)
{
	char **tok;

	if (!tokens)
	{
		return;
	}

	tok = *tokens;
	if (!tok)
		return;

	while (*tok)
		free(*tok++);
	free(*tokens);

	*tokens = NULL;
}
