#include "hsh.h"

/**
 * expand_aliases - execute looping alias etxtension to current command
 * @aliases: list of alias
 * @tokptr: pointed existing  tokens
 *
 * Return: If extension is correct, return pointer t on otherwise 0
 */
void expand_aliases(alias_t *aliases, char ***tokptr)
{
	char **new, **old, *name, *value, *temp;

	if (!*tokptr)
		return;
	do {
		name = expand_alias(aliases, tokptr);
		value = get_dict_val(aliases, name);
		if (value && *value && _isspace(value[_strlen(value) - 1]))
		{
			old = *tokptr;
			new = arrdup(old + 1);

			expand_aliases(aliases, &new);
			temp = *(old + 1);

			*(old + 1) = NULL;
			*tokptr = arrjoin(old, new);
			*(old + 1) = temp;

			free_tokens(&old);
			free_tokens(&new);
		}
	} while (name && **tokptr && _strcmp(name, **tokptr));
}


/**
 * expand_alias - execute alias extension for current command
 * @aliases: list of arrenged aliases
 * @tokptr: pointed existing tokens
 *
 * Return: if extension is correct, retur  pointer alias.
 * Otherwise, return void.
 */
char *expand_alias(alias_t *aliases, char ***tokptr)
{
	char **alias_tokens, **tokens = *tokptr;

	if (!*tokens)
		return (NULL);

	while (aliases)
	{
		if (!_strcmp(*tokens, aliases->key))
		{
			alias_tokens = tokenize(aliases->val);
			*tokptr = arrjoin(alias_tokens, tokens + 1);

			free_tokens(&tokens);
			free_tokens(&alias_tokens);

			return (aliases->key);
		}
		aliases = aliases->next;
	}
	return (NULL);
}
