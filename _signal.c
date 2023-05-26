#include "hsh.h"

/**
  * _sigint - reminders
  * @signal: identified singal
  */
void _sigint(int signal __attribute__((unused)))
{
	fflush(STDIN_FILENO);
	write(STDERR_FILENO, "\n$ ", 3);
}
