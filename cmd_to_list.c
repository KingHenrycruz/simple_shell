#include "command.h"

/**
 * cmd_to_list - build a linked to devided commands
 * @cmd: observed commands
 *
 * Return: If assigned memory decliness, return NULL. Otherwise, return a
 * new list pointed hearder
 */
cmdlist_t *cmd_to_list(const char *cmd)
{
	cmdlist_t *head = NULL;
	size_t count;
	char *split = _strdup(cmd);

	if (!split)
		return (NULL);

	count = split_cmd(split);

	if (!_cmd_to_list(&head, split, count))
	{
		free_cmdlist(&head);
		return (NULL);
	}
	free(split);

	return (head);
}


/**
 * _cmd_to_list - build a reminded link to helper-command
 * @tailptr: pointed command tail
 * @split: spliter void  bytes on splitters
 * @count: contained splitter output
 *
 * Return: If assigned memory is void, return NULL. Otherwise, return a
 * pointed new tail list.
 */
cmdlist_t *_cmd_to_list(cmdlist_t **tailptr, char *split, size_t count)
{
	cmdlist_t *tail;

	if (!count)
		return (*tailptr);

	tail = add_cmd_end(tailptr, split);
	if (!tail)
		return (NULL);

	while (*split++)
		;

	return (_cmd_to_list(&tail, split, count - 1));
}
