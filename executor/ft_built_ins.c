#include "../include/minishell.h"

size_t	ft_has_builtin(t_list *cmd_list)
{
	if (ft_strncmp(cmd_list->key, "echo", 4) == 0)
		return (0);
	if (ft_strncmp(cmd_list->key, "cd", 2) == 0)
		return (0);
	if (ft_strncmp(cmd_list->key, "pwd", 3) == 0)
		return (0);
	if (ft_strncmp(cmd_list->key, "export", 6) == 0)
		return (0);
	if (ft_strncmp(cmd_list->key, "unset", 5) == 0)
		return (0);
	if (ft_strncmp(cmd_list->key, "env", 3) == 0)
		return (0);
	if (ft_strncmp(cmd_list->key, "exit", 4) == 0)
		return (0);
	return (1);
}

void	ft_exec_buitin(t_list *cmd_list)
{
	if (ft_strncmp(cmd_list->key, "echo", 4) == 0)
		ft_echo (cmd_list);
	if (ft_strncmp(cmd_list->key, "cd", 2) == 0)
		ft_cd (cmd_list);
	if (ft_strncmp(cmd_list->key, "pwd", 3) == 0)
		ft_pwd (cmd_list);
	if (ft_strncmp(cmd_list->key, "export", 6) == 0)
		ft_export (cmd_list);
	if (ft_strncmp(cmd_list->key, "unset", 5) == 0)
		ft_unset (cmd_list);
	if (ft_strncmp(cmd_list->key, "env", 3) == 0)
		ft_env (cmd_list);
	if (ft_strncmp(cmd_list->key, "exit", 4) == 0)
		ft_exit (cmd_list);
	return ;
}
