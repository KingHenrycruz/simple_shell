#ifndef _ERROR_H_
#define _ERROR_H_

#include "string.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

void perrorl_default(const char *arg0, size_t lineno, const char *msg, ...);
void perrorl(const char *msg, ...);

#endif
