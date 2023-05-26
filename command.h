#ifndef COMMAND_H
#define COMMAND_H

#include <stdlib.h>
#include "tokens.h"
#include "types.h"
#include "quote.h"
#include "string.h"

/**
 * enum cmdlist_sep_n - Numeric val for cmd list seperators
 * @SEMICOLON: Semicolon separator ;
 * @AMPERSAND: Ampersand separator &
 * @AND: AND separator &&
 * @OR: OR separator ||
 */

typedef enum cmdlist_sep_n
{
	SEMICOLON = 1,
	AMPERSAND = 2,
	AND       = 4,
	OR        = 8
} cmdlist_sep_n_t;

/**
 * struct cmdlist_sep - cmd list seperator
 * @sep: Seperator for preceeding list
 * @n: Numeric val correspondence
 */

typedef struct cmdlist_sep
{
	const char *sep;
	enum cmdlist_sep_n n;
} cmdlist_sep_t;

/**
 * struct cmdlist - cmd Linked list
 * @next: Next cmd to be exec
 * @tree: Binary cmd tree
 * @tokens: cmd tokens in the tree
 */
struct cmdlist
{
	struct cmdlist *next;
	struct cmdtree *tree;
	char **tokens;
};

/**
 * struct cmdtree - Binary tree of CMDs
 * @tokens: simple cmd with no seperator
 * @success: Command to be executed upon failure
 * @failure: Command to be executed upon success
 * @sep: Separator for preceeding list
 */
struct cmdtree
{
	struct cmdtree *success;
	struct cmdtree *failure;
	const char * const *tokens;
	struct cmdlist_sep sep;
};

size_t split_cmd(char *cmd);

char **pop_cmd(cmdlist_t **headptr);
void free_cmdlist(cmdlist_t **headptr);

cmdlist_t *cmd_to_list(const char *cmd);
cmdlist_t *_cmd_to_list(cmdlist_t **tailptr, char *split, size_t count);
cmdlist_t *add_cmd_end(cmdlist_t **headptr, const char *cmd);
cmdlist_t *del_cmd(cmdlist_t **headptr, size_t index);

cmdtree_t *cmd_to_tree(const char * const *tokens);
void free_cmdtree(cmdtree_t **rootptr);

#endif /* COMMAND_H */
