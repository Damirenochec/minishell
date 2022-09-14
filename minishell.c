/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:58:52 by paolives          #+#    #+#             */
/*   Updated: 2022/09/14 15:05:30 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// после запуска программы он выведет строку "my_shell->" и будет
// ждать ввода и выведет введенную строку в терминал

char	*write_error(char *error)
{
	printf("%s\n", error);
	return (NULL);
}

void print_mass(char **str)
{
	while (*str)
	{
		printf("mass %s\n", *str);
		str++;
	}
	
}

void	print_lst_tokken(t_list *list)
{
	while (list)
	{
		printf("%s %s\n", (char*)list->key, (char*)list->value);
		list = list->next;
	}
}

void	print_lst_cmd(t_list *list)
{
	while (list)
	{
		if (get_type_tokken(list->key) == 6)
			print_mass(list->value);
		else
			printf("tokken %s %s\n", (char*)list->key, (char*)list->value);
		list = list->next;
	}
}

void	my_sig_ctrl_c(int i)
{
	if (i == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

int	main(int argc, char **env)
{
	char	*a;
	t_info	*info;
	//int	i = 0;
	//t_list *list;

	if (argc != 1)
	{
		write_error("Wrong number of arguments");
	}
	info = make_info(env);
	signal(SIGINT, my_sig_ctrl_c);
	while (1)
	{
		a = readline("my_shell->");
		if (a == NULL)
			break;
		else if (*a == '\0')
			free(a);
		else
		{
			add_history(a);
			lexer(a, info);
			parcer(info);
			
			print_lst_cmd(info->cmd_list);
			
			free(a);
			free_list(info->start);
			free_cmd(info->cmd_list);
			info->start = NULL;
			info->cmd_list = NULL;
		}
	}
	free_env(info->env_list);
	free(info);
	return (0);
}
