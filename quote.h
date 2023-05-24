#ifndef _QUOTE_H_
#define _QUOTE_H_

#include "ctype.h"
#include <stdlib.h>
#include "string.h"

/**
 * @QUOTE_WORD: The unranked list of non-blanks
 * @QUOTE_DOUBLE: doubled quotes
 * @QUOTE_SINGLE: The single value
 * enum quote_state - The quote that list clue
 * @QUOTE_NONE: Do not quote output
 * @QUOTE_SINGLE: The single value
 * @QUOTE_ESCAPE: Sequent a backslash
 */
typedef enum quote_state
{
	QUOTE_NONE   = 0x0,
	QUOTE_WORD   = 0x1,
	QUOTE_DOUBLE = 0x2,
	QUOTE_SINGLE = 0x4,
	QUOTE_ESCAPE = 0x8
} quote_state_t;

typedef size_t (*quote_state_fp)(const char *, quote_state_t *);

quote_state_t quote_state(char c);

quote_state_fp quote_state_f(quote_state_t s);

size_t quote_state_len(const char *str, quote_state_t state);
size_t _quote_state_none(const char *str, quote_state_t *state);
size_t _quote_state_word(const char *str, quote_state_t *state);
size_t _quote_state_double(const char *str, quote_state_t *state);
size_t _quote_state_single(const char *str, quote_state_t *state);
size_t _quote_state_escape(const char *str, quote_state_t *state);

int _isspecial_double(char c);

char *dequote(const char *str);
size_t dequote_len(const char *str);

#endif
