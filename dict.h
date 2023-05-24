#ifndef _DICT_H_
#define _DICT_H_

#include "string.h"
#include <stdlib.h>

#include "types.h"

/**
  * @typedef struct dict - singly linked list for key values
  * @history: arguments used 
  * @commands: arguments used 
  * @path: arguments used 
  * @aliases: arguments used 
  * @line: arguments used 
  * @lineno: arguments entered 
  * @tokens: arguments used 
  * @pid: used arguments
  * @key: the var name
  * @next: point to next node
  * @val: var value
  */

struct dict
{
	char *key;
	char *val;
	struct dict *next;
};

dict_t *del_dict_node(dict_t **headptr, const char *key);
void free_dict(dict_t **headptr);
char *get_dict_val(dict_t *head, const char *key);
dict_t *add_dict_node_end(dict_t **headptr, const char *key, const char *val);
dict_t *get_dict_node(dict_t *head, const char *key);

#endif
