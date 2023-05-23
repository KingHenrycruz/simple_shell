#ifndef TOKENS_H
#define TOKENS_H

#include "string.h"
#include <stdlib.h>
#include "quote.h"

size_t count_tokens_noquote(const char *str);
char **arrjoin(char **arr1, char **arr2);

char **tokenize(const char *str);
char **tokenize_noquote(const char *str);

char **arrdup(char **arr);
size_t count_tokens(const char *str);

void free_tokens(char ***tokens);

#endif
