#ifndef CTYPE_H
#define CTYPE_H

#include <stdlib.h>
#include <stdbool.h>

bool _isident(int c);
bool _isspace(int c);
bool _isquote(int c);

bool _isnumber(const char *s);

bool _isalnum(int c);
bool _isalpha(int c);
bool _isdigit(int c);

#endif
