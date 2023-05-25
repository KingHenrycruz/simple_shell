#include "list.h"

/**
 * str_to_list - Helps turn strings to linked-list
 * @str: The string inputted
 * @delim: Acronym to depict delimiter passed
 * Return: Serves as a pointer to list
 */
list_t *str_to_list(const char *str, char delim)
{
	list_t *head = NULL;

	if (!str)
		return (NULL);

	if (!_str_to_list(&head, str, delim))
		free_list(&head);

	return (head);
}


/**
 * _str_to_list - Helps turn strings to linked-list
 * @tailptr: We keep addng strings to list tail
 * @str: Acronym for depicting string
 * @delim: Can be taken for str delimiter
 * Return: We keep addng strings to list tail
 */
list_t *_str_to_list(list_t **tailptr, const char *str, char delim)
{
	list_t *tail;
	ssize_t len = _strchr(str, delim);

	if (len == -1)
		len = _strlen(str);

	tail = add_node_end(tailptr, NULL);
	if (!tail)
		return (NULL);

	tail->str = _memdup(str, len + 1);
	if (!tail->str)
		return (NULL);

	tail->str[len] = '\0';

	if (str[len])
		return (_str_to_list(&tail, str + len + 1, delim));

	return (tail);
}


/**
 * add_node - We keep addng strings to list head
 * @headptr: This node is the first on the list
 * @str: Added string to list
 * Return: NULL if memory alloc fails
 */
list_t *add_node(list_t **headptr, const char *str)
{
	list_t *new;

	if (!headptr)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = _strdup(str);
	new->next = *headptr;

	*headptr = new;

	return (new);
}


/**
 * add_node_end - We keep addng strings to list tail
 * @headptr: This node is the first on the list
 * @str: Added string to list
 * Return: NULL if memory alloc fails
 */
list_t *add_node_end(list_t **headptr, const char *str)
{
	list_t *new;

	if (!headptr)
		return (NULL);

	if (*headptr)
		return (add_node_end(&((*headptr)->next), str));

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = _strdup(str);
	new->next = *headptr;

	*headptr = new;

	return (new);
}


/**
 * free_list - Set head to NULL after freeing the linked list.
 * @headptr: This node is the first on the list
 */
void free_list(list_t **headptr)
{
	if (!*headptr)
		return;

	free_list(&((*headptr)->next));
	free((*headptr)->str);
	free(*headptr);
	*headptr = NULL;
}
