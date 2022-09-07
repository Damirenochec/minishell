#include "../include/minishell.h"

/*
 * Нужно сделать проект таким образом
 * Первая функция - распознает тип key
 * После парсера есть следующие типы key
 * 1) word
 * 2) <   >    <<    >> - т.е. редиректы
 * 3) |  - т.е. пайп
 *
 * Еще нужно подумать про реализацию функции EXPORT
 * Она записывает новую переменную в окружение
 *
 */

void	ft_exec_cmd(t_list *cmd_list)
{
	if (ft_has_builtin(cmd_list) == 0)
		ft_exec_builtin(cmd_list);
	else
		ft_execve(cmd_list);
	return ;
}

void	executor(t_list *cmd_list)
{
	if (ft_strncmp(cmd_list->key, "|", 1))
		ft_pipe(cmd_list);
	else if (ft_strncmp(cmd_list->key, "<", 1))
		ft_redir(cmd_list);
	else if (ft_strncmp(cmd_list->key, ">", 1))
		ft_redir(cmd_list);
	else if (ft_strncmp(cmd_list->key, ">>", 2))
		ft_redir(cmd_list);
	else if (ft_strncmp(cmd_list->key, "<<", 2))
		ft_redir(cmd_list);
	else if (ft_strncmp(cmd_list->key, "<<", 2))
		ft_redir(cmd_list);
	else if (ft_strncmp(cmd_list->key, "word", 4))
		ft_exec_cmd(cmd_list);
	return ;
}