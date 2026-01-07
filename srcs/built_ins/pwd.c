#include "../../minishell.h"

int	ft_pwd(char **argv, t_shell *shell)
{
	t_envar	*pwd_var;
	char	*pwd_str;

	if (!argv[0])
		return (shell->last_exit = -1);
	pwd_var = ft_get_envar(shell->envc, "PWD", shell->err);
	pwd_str = NULL;
	if (!pwd_var)
		pwd_str = getcwd(NULL, 0);
	else
		pwd_str = ft_strdup(pwd_var->value);
	ft_putendl_fd(pwd_str, STDOUT_FILENO);
	free(pwd_str);
	return (shell->last_exit = 0);
}
