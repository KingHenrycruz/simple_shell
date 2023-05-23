#ifndef _INFO_H_
#define _INFO_H_

#include <unistd.h>
#include <stdlib.h>

#include "env.h"
#include "tokens.h"
#include "alias.h"
#include "types.h"
#include "error.h"
#include "getline.h"
#include "history.h"
#include "list.h"
#include "string.h"

extern char **environ;

/**
  * struct info - shell state
  * @interactive: arguments passed
  * @argc: arguments count
  * @argv: arguments values
  * @file: passed arguments
  * @fileno: arguments passed
  * @status: passed arguments
  * @cwd: arguments passed
  * @exe: arguments passed
  * @env: arguments passed
  * @history: arguments passed
  * @commands: arguments passed
  * @path: arguments passed
  * @aliases: passed arguments
  * @line: arguments passed
  * @lineno: arguments passed
  * @tokens: passed arguments
  * @pid: passed arguments
  */

struct info
{
	int interactive;
	int argc;
	char **argv;
	char *file;
	alias_t *aliases;
	history_t *history;
	cmdlist_t *commands;
	char **tokens;
	pid_t pid;
	char *cwd;
	char *exe;
	env_t *env;
	int fileno;
	int status;
	char *line;
	size_t lineno;
	list_t *path;
};

info_t *init_info(int argc, char **argv);
int free_info(info_t *info);

#endif

