#include "../../minishell.h"

int	ft_isnum_str(char *s)
{
	if (!s)
		return (0);
	while (*s && ft_isdigit(*s))
		s++;
	if (*s)
		return (0);
	return (1);
}

int	ft_exit(char **argv, t_pipe *pipeline, t_shell *shell)
{
	int	value;

	value = 0;
	if (argv && argv[1])
	{
		ft_printf("exit\n");
		if (argv[2])
		{
			perror("Error: Too many arguments\n");
			return (shell->last_exit = -1);
		}
		if (argv[1] && ft_isnum_str(argv[1]))
			value = ft_atoi(argv[1]);
		else
		{
			perror("Error: Numerical argument required\n");
			value = 2;
		}
	}
	if (pipeline)
		ft_del_pipeline(&pipeline, shell->err);
	if (shell)
		ft_del_shell(&shell);
	rl_clear_history();
	exit(value);
}
