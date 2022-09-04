/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:36:22 by paolives          #+#    #+#             */
/*   Updated: 2022/09/04 15:28:26 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	get_type_tokken(char *tokken)
{
	if (!ft_strncmp(tokken, ">", 1))
		return (1);
	else if (!ft_strncmp(tokken, "<", 1))
		return (2);
	else if (!ft_strncmp(tokken, ">>", 2))
		return (3);
	else if (!ft_strncmp(tokken, "<<", 2))
		return (4);
	else if (!ft_strncmp(tokken, "|", 1))
		return (5);
	else if (!ft_strncmp(tokken, "word", 4))
		return (6);
	else
		return (0);
}

char	**add_cmd_arg(char **cmd,char *arg)
{
	char	**ptr;
	char	**ptr2;
	if (cmd == NULL)
	{
		ptr = cmd;
		cmd = malloc(sizeof(char*) * 2);
		*cmd = arg;
		*(cmd + 1) = NULL;
		free(ptr);
		return (cmd);
	}
	else
	{
		ptr = malloc(sizeof(cmd) + sizeof(char*));
		ptr2 = ptr;
		while (*cmd)
		{
			*ptr = *cmd;
			ptr++;
			cmd++;
		}
		*ptr = arg;
		ptr++;
		*ptr = NULL;
		free(cmd);
		return(ptr2);
	}
}

void	parcer(t_info *info)
{
	t_list	*list;
	t_list	*open_rd;
	t_list	*close_rd;
	t_list	*ptr;
	char	**str;
	int		i;
	int		j;

	list = info->start;
	str = NULL;
	open_rd = NULL;
	close_rd = NULL;
	if (get_type_tokken(list->key) == 5)
		write_error("syntax error near unexpected token \'|\'");
	while (ptr)
	{
		if (get_type_tokken(list->key) == 1 && get_type_tokken(list->key) == 3)
		{
			if (get_type_tokken(list->next->key) == 6)
			{
				if (get_type_tokken(list->key) == 2 || get_type_tokken(list->key) == 4)
					ft_lstadd_back(&open_rd, ft_lstnew(list->key, list->next->value));
				else
					ft_lstadd_back(&close_rd, ft_lstnew(list->key, list->next->value));
				list = list->next;
			}
			else
				write_error("syntax error near unexpected token");
		}
		else if (get_type_tokken(ptr->key) == 6)
		{
			str = add_cmd_arg(str, ptr->value);
		}
		else if (get_type_tokken(list->key) == 5)
		{
			if (open_rd)
				ft_lstadd_back(&(info->cmd_list), open_rd);
			if (str)
				ft_lstadd_back(&(info->cmd_list), ft_lstnew("word", str));
			if (close_rd)
				ft_lstadd_back(&(info->cmd_list), close_rd);
			ft_lstadd_back(&(info->cmd_list), ft_lstnew("|", NULL));
			open_rd = NULL;
			close_rd = NULL;
			str = NULL;
		}
			
		list = list->next;
	}
	while (info->cmd_list)
	{
		printf("cmd %s %s\n", info->cmd_list->key, info->cmd_list->value);
		if (info->cmd_list->next == NULL)
			break;
		info->cmd_list = info->cmd_list->next;
	}
	
}