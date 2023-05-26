#include "command.h"

/**
 * cmd_to_tree - A binary tree of commands
 * @tokens: cmd to be parsed
 * Return: 1 if the character is a digit, 0 otherwise.
 */
cmdtree_t *cmd_to_tree(const char * const *tokens __attribute__((unused)))
{
	return (NULL);
}

/**
 * free_cmdtree - Free  binary tree then set root to NULL
 * @rootptr: pointer to the root
 * Return: NULL value
 */
void free_cmdtree(cmdtree_t **rootptr)
{
	if (rootptr && *rootptr)
	{
		free_cmdtree(&((*rootptr)->failure));
		free_cmdtree(&((*rootptr)->success));
		(*rootptr) = NULL;
		(*rootptr)->tokens = NULL;
	}
}
