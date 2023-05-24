#include "error.h"

/**
  * perrorl - the printed standard error output
  * @msg:output values
  * @...: NULL-elapsed context strings arranged
  */
void perrorl(const char *msg, ...)
{
	const char *str;
	va_list context;

	va_start(context, msg);
	while ((str = va_arg(context, char *)))
	{
		write(STDERR_FILENO, str, _strlen(str));
		write(STDERR_FILENO, ": ", 2);
	}
	va_end(context);

	if (msg)
		write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, "\n", 1);
}


/**
  * perrorl_default - printed standard error output
  * @arg0: vector arguments
  * @lineno:arrenged values
  * @msg: error values
  * @...: NULL-elapsed context strings arranged
  */
void perrorl_default(const char *arg0, size_t lineno, const char *msg, ...)
{
	char *linenostr = num_to_str(lineno);
	const char *str = NULL;
	va_list ap;

	if (arg0)
		write(STDERR_FILENO, arg0, _strlen(arg0));
	write(STDERR_FILENO, ": ", 2);

	if (linenostr)
		write(STDERR_FILENO, linenostr, _strlen(linenostr));
	write(STDERR_FILENO, ": ", 2);

	va_start(ap, msg);
	while ((str = va_arg(ap, char *)))
	{
		write(STDERR_FILENO, str, _strlen(str));
		write(STDERR_FILENO, ": ", 2);
	}
	va_end(ap);

	if (msg)
		write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	free(linenostr);
}
