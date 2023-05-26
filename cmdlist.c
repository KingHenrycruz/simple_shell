#include "command.h"


/**
 * add_cmd_end - Adding command(s) to list end/tail
 * @cmd: specific comd to be added to list
 * @headptr: Pointer to first list node
 * Return: 1 if the character is alphabetic, 0 otherwise.
 */
cmdlist_t *add_cmd_end(cmdlist_t **headptr, const char *cmd)
{
	cmdlist_t *new;

	if (!headptr)
		return (NULL);
	if (*headptr)
		return (add_cmd_end(&((*headptr)->next), cmd));

	new = malloc(sizeof(cmdlist_t));
	if (!new)
		return (NULL);

	new->next = NULL;
	new->tree = NULL;

	new->tokens = tokenize(cmd);
	if (!new->tokens)
	{
		free(new);
		return (NULL);
	}
	*headptr = new;

	return (new);
}


/**
 * del_cmd - Extracting a particular command from a list
 * @headptr: Pointer to first node
 * @ind: argument keyed in
 * Return: deleted node's address
 */
cmdlist_t *del_cmd(cmdlist_t **headptr, size_t ind)
{
	cmdlist_t *old;

	if (!(headptr && *headptr))
		return (NULL);
	if (ind)
		return (del_cmd(&((*headptr)->next), ind - 1));

	old = *headptr;
	*headptr = (*headptr)->next;
	free_cmdtree(&(old->tree));
	free_tokens(&(old->tokens));
	free(old);

	return (old);
}


/**
 * pop_cmd - Retrieve node's after removing it
 * @headptr: Pointer to first node
 * Return: Tokens as command
 */
char **pop_cmd(cmdlist_t **headptr)
{
	cmdlist_t *pop;
	char **tokens;

	if (!(headptr && *headptr))
		return (NULL);

	pop = *headptr;
	tokens = pop->tokens;
	*headptr = (*headptr)->next;

	free_cmdtree(&(pop->tree));
	free(pop);

	return (tokens);
}


/**
 * free_cmdlist - Set head to NULL after freeing linked list
 * @headptr: pointer to first node
 */
void free_cmdlist(cmdlist_t **headptr)
{
	if (headptr && *headptr)
	{
		free_cmdtree(&((*headptr)->tree));
		free_tokens(&((*headptr)->tokens));
		free_cmdlist(&((*headptr)->next));
		free(*headptr);
		*headptr = NULL;
	}
}
