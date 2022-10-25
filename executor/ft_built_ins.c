#include "../include/minishell.h"

size_t	ft_has_builtin(t_list *cmd_list)
{
	if (ft_strncmp(cmd_list->value[0], "echo", 4) == 0)
		return (0);
	if (ft_strncmp(cmd_list->value[0], "cd", 2) == 0)
		return (0);
	if (ft_strncmp(cmd_list->value[0], "pwd", 3) == 0)
		return (0);
	if (ft_strncmp(cmd_list->value[0], "export", 6) == 0)
		return (0);
	if (ft_strncmp(cmd_list->value[0], "unset", 5) == 0)
		return (0);
	if (ft_strncmp(cmd_list->value[0], "env", 3) == 0)
		return (0);
	if (ft_strncmp(cmd_list->value[0], "exit", 4) == 0)
		return (0);
	return (1);
}

void	ft_exec_builtin(t_list *cmd_list, t_list *env_list)
{
	if (ft_strncmp(cmd_list->value[0], "echo", 4) == 0)
		ft_echo (cmd_list);
	if (ft_strncmp(cmd_list->value[0], "cd", 2) == 0)
		ft_cd (cmd_list, env_list);
	if (ft_strncmp(cmd_list->value[0], "pwd", 3) == 0)
		ft_pwd (void);
	if (ft_strncmp(cmd_list->value[0], "export", 6) == 0)
		ft_export (cmd_list, env_list);
	if (ft_strncmp(cmd_list->value[0], "unset", 5) == 0)
		ft_unset (cmd_list);
	if (ft_strncmp(cmd_list->value[0], "env", 3) == 0)
		ft_env (cmd_list);
	if (ft_strncmp(cmd_list->value[0], "exit", 4) == 0)
		ft_exit (cmd_list);
	return ;
}
