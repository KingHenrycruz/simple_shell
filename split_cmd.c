#include "command.h"

/**
 * split_cmd -  split a command by replacing unquoted semicolons with NULL bytess
 * @cmd: Command to be splitted
 * Return: total number of commands that result from splitting the given command by replacing unquoted semicolons with NULL bytes.
 */
size_t split_cmd(char *cmd)
{
	size_t count = 1, state_len;
	ssize_t sep_index;
	quote_state_t state;

	do {
		while (*cmd && (state = quote_state(*cmd)) != QUOTE_NONE)
		{
			if (state & QUOTE_WORD)
			{
				state_len = _quote_state_word(cmd, NULL);
				sep_index = _strnchr(cmd, ';', state_len);
				if (sep_index != -1)
				{
					state_len = sep_index;
					*(cmd++ + state_len) = '\0';
					++count;
				}
				cmd += state_len;
			}
			else if (state & QUOTE_ESCAPE)
			{
				if (*(cmd + 1) == '\n')
					_strcpy(cmd, cmd + 2);
				else if (*(++cmd))
					++cmd;
			}
			else
			{
				cmd += quote_state_len(cmd + 1, state) + 1;
				if (*cmd && (state & (QUOTE_SINGLE | QUOTE_DOUBLE)))
					++cmd;
			}
		}
	} while (*(cmd += quote_state_len(cmd, QUOTE_NONE)));

	return (count);
}
