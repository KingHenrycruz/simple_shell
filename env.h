#ifndef _ENV_H_
#define _ENV_H_

#include "string.h"
#include "dict.h"
#include "types.h"
#include <stdlib.h>

typedef dict_t env_t;

env_t *_env_to_dict(env_t **tailptr, char **env);
env_t *env_to_dict(char **env);
char **dict_to_env(env_t *head);

#endif
