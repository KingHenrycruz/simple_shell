#ifndef _DICT_H_
#define _DICT_H_

#include <stdlib.h>

#include "string.h"
#include "types.h"

/**
  * struct dict - singly linked list of key-value pairs
  * @key: variable name
  * @next: pointer to the next node
  * @val: value of variable
  * @next: pointer to the next node
  */
struct dict
{
	char *val;
	char *key;
	struct dict *next;
};

char *get_dict_val(dict_t *head, const char *key);
dict_t *del_dict_node(dict_t **headptr, const char *key);
dict_t *get_dict_node(dict_t *head, const char *key);
dict_t *add_dict_node_end(dict_t **headptr, const char *key, const char *val);
void free_dict(dict_t **headptr);

#endif /* _DICT_H_ */
