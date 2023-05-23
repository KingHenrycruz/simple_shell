#ifndef _BUILTINS_H_
#define _BUILTINS_H_

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#include "string.h"
#include "types.h"
#include "error.h"
#include "info.h"
#include "alias.h"
#include "env.h"
#include "path.h"


#define HELP_HELP "help [BUILTIN]"
#define HELP_DESC								\
	"Display information about builtin commands.\n\0"			\
	"If BUILTIN is omitted, the available commands are displayed.\0"	\
	"\0"

#define SETENV_HELP "setenv [NAME [VALUE]]"
#define SETENV_DESC								\
	"Set the environment variable NAME to VALUE.\n\0"			\
	"If NAME is omitted, the shell execution environment is displayed.\0"	\
	"If VALUE is omitted, the value of NAME is set to an empty string.\0"	\
	"\0"

#define UNSETENV_HELP "unsetenv NAME"
#define UNSETENV_DESC								\
	"Remove the variable NAME from the environment.\0"			\
	"\0"
#define ENV_HELP "env"
#define ENV_DESC								\
	"Print the environment.\0"						\
	"\0"

#define EXEC_HELP "exec COMMAND [ARGS ...]"
#define EXEC_DESC								\
	"Replace the shell with the given command.\n\0"				\
	"COMMAND is executed, replacing the executing shell.\0"			\
	"ARGS are passed as positional arguments to COMMAND.\0"			\
	"If the command cannot be executed, the shell exits.\0"			\
	"\0"

#define ALIAS_HELP "alias [KEY[=VALUE] ...]"
#define ALIAS_DESC								\
	"Define and display aliases.\n\0"					\
	"If given no arguments, existing alias definitions are displayed.\0"	\
	"Otherwise, an alias is defined for each KEY=VALUE pair provided.\0"	\
	"For each KEY with no VALUE the corresponding alias is displayed.\0"	\
	"If VALUE ends with a space, the following word will be expanded.\0"	\
	"\0"

#define CD_HELP "cd [DIR]"
#define CD_DESC									\
	"Change the current working directory to DIR.\n\0"			\
	"If DIR is omitted, it defaults to the value of the variable HOME.\0"	\
	"If DIR is -, the current directory reverts to its previous value.\0"	\
	"\0"

#define EXIT_HELP "exit [STATUS]"
#define EXIT_DESC								\
	"Exit the shell with a status of STATUS.\n\0"				\
	"If STATUS is omitted, the exit status is that of the last command.\0"	\
	"\0"


typedef int (*builtin_fp)(info_t *);

/**
 * struct builtin - commandds that are builtin
 * @f: called function
 * @help: how to use the command
 * @desc: description of entered commands
 * @name: names of the commands
 */

struct builtin
{
	const char *name;
	builtin_fp f;
	const char *help;
	const char *desc;
};

const struct builtin *get_builtins(void);
const struct builtin *get_builtin(const char *name);

int __history(info_t *info);
int __setenv(info_t *info);
int __unsetenv(info_t *info);
int __alias(info_t *info);
int __cd(info_t *info);
int __env(info_t *info);
int __exec(info_t *info);
int __exit(info_t *info);
int __help(info_t *info);

#endif
