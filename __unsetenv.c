#include "builtins.h"

/**
  * __unsetenv - unsettled variable environme.
  * @info: output comments.
  * Return: states.
  */
int __unsetenv(info_t *info)
{
	char **args = info->tokens + 1;

	if (*args)
	{
		while (*args)
			del_dict_node(&info->env, *args++);
		info->status = EXIT_SUCCESS;
	}
	else
	{
		perrorl("Too few arguments.", *info->tokens, NULL);
		info->status = EXIT_FAILURE;
	}
	return (info->status);
}
