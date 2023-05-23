#include "builtins.h"

/**
 * __cd_error - error to be printed upon failure to change directory
 * @info: information of the shell
 * @dir: the directory to be entered
 */
void __cd_error(info_t *info, char *dir)
{
	char *error = strjoin(NULL, " ", "can't cd to", dir);

	perrorl_default(*info->argv, info->lineno, error, *info->tokens, NULL);

	info->status = 2;

	free(error);
}


/**
 * __cd_success - upon success, update the environment
 * @info: the shell information
 */
void __cd_success(info_t *info)
{
	char **tokens = info->tokens;
	char *setenv_tokens[] = {"setenv", NULL, NULL, NULL};

	info->tokens = setenv_tokens;

	setenv_tokens[1] = "OLDPWD";
	setenv_tokens[2] = info->cwd;

	__setenv(info);

	free(info->cwd);
	info->cwd = getcwd(NULL, 0);

	setenv_tokens[1] = "PWD";
	setenv_tokens[2] = info->cwd;

	__setenv(info);

	info->tokens = tokens;

	info->status = EXIT_SUCCESS;
}


/**
 * __cd - Here, We CD: changes the directory
 * @info: Information of the arguments passed/entered
 *
 * Return: integer value
 */
int __cd(info_t *info)
{
	char *dir = NULL, **args = info->tokens + 1;

	info->status = EXIT_SUCCESS;
	if (*args)
	{
		if (!_strcmp(*args, "-"))
		{
			dir = get_dict_val(info->env, "OLDPWD");
			if (!dir)
				dir = info->cwd;

			info->status = chdir(dir);
			if (!info->status)
			{
				write(STDOUT_FILENO, dir, _strlen(dir));
				write(STDOUT_FILENO, "\n", 1);
			}
		}
		else
		{
			dir = *args;
			info->status = chdir(dir);
		}
	}
	else
	{
		dir = get_dict_val(info->env, "HOME");
		if (dir)
			info->status = chdir(dir);
	}
	if (info->status != -1)
		__cd_success(info);
	else
		__cd_error(info, dir);

	return (info->status);
}
