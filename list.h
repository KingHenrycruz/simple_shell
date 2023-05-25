#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include "types.h"
#include "string.h"

/**
 * struct list - lists that are linked singly
 * @next: a pointer that points to the next node
 * @str: Strings allocated dynamically
 */
struct list
{
	char *str;
	struct list *next;
};

list_t *add_node(list_t **headptr, const char *str);
list_t *add_node_end(list_t **headptr, const char *str);
list_t *str_to_list(const char *str, char delim);
void free_list(list_t **headptr);
list_t *_str_to_list(list_t **tailptr, const char *str, char delim);

#endif
