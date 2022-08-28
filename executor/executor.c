#include "../include/minishell.h"

/*
 * Нужно сделать проект таким образом
 * Первая функция - распознает тип key
 * После парсера есть следующие типы key
 * 1) REDIRECT
 * 2) PIPE
 * 3) COMMAND
 *
 * Еще нужно подумать про реализацию функции EXPORT
 * Она записывает новую переменную в окружение
 *
 */

void	ft_exec_cmd(t_list *cmd_list)
{
	if (ft_has_builtin(cmd_list) == 0)
		ft_exec_buitin(cmd_list);
	else
		ft_execve(cmd_list);
	return ;
}

void	executor(t_list *cmd_list)
{
	if (cmd_list->key == PIPE)
		ft_pipe(cmd_list);
	else if (cmd_list->key == REDIRECT)
		ft_redir(cmd_list);
	else
		ft_exec_cmd(cmd_list);
	return ;
}