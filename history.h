#ifndef HISTORY_H
#define HISTORY_H

#include "list.h"
#include "types.h"

/**
  * struct history - History of command shell
  * @head: Pointer to start/head node
  * @filename: File name of history file
  * @n: num of entries in list
  */
struct history
{
	struct list *head;
	char *filename;
	size_t n;
};

#endif /* HISTORY_H */
