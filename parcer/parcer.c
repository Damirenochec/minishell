/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:36:22 by paolives          #+#    #+#             */
/*   Updated: 2022/09/10 09:36:11 by paolives         ###   ########.fr       */
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

char	**lst_to_arr(t_list *list)
{
	char	**str;
	char	**ptr;

	str = malloc((ft_lstsize(list) + 1) * sizeof(char *));
	ptr = str;
	while (list)
	{
		*str = list->value;
		str++;
		list = list->next;
	}
	*str = NULL;
	return (ptr);
}

// t_list	*parce_redirect(t_list *list)
// {
// 	if (list->next && get_type_tokken(list->next->key) == 6)
// }


void	parcer(t_info *info)
{
	t_list	*list;
	t_list	*open_rd;
	t_list	*close_rd;
	t_list	*ptr;
	t_list	*str;
	int		i;
	int		j;

	list = info->start;
	str = NULL;
	open_rd = NULL;
	close_rd = NULL;
	if (get_type_tokken(list->key) == 5)
		write_error("syntax error near unexpected token \'|\'");
	while (list)
	{
		if (get_type_tokken(list->key) >= 1 && get_type_tokken(list->key) <= 4)
		{
			if (list->next && get_type_tokken(list->next->key) == 6)
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
		else if (get_type_tokken(list->key) == 6)
		{
			ft_lstadd_back(&str, ft_lstnew(list->key, list->value));
		}
		else if (get_type_tokken(list->key) == 5 || list->next == NULL)
		{
			if (!list->next || get_type_tokken(list->next->key) != 6)
				write_error("syntax error near unexpected token");
			if (open_rd != NULL)
				ft_lstadd_back(&(info->cmd_list), open_rd);
			if (str != NULL)
				ft_lstadd_back(&(info->cmd_list), ft_lstnew("word", lst_to_arr(str)));
			if (close_rd != NULL)
				ft_lstadd_back(&(info->cmd_list), close_rd);
			ft_lstadd_back(&(info->cmd_list), ft_lstnew("|", NULL));
			open_rd = NULL;
			close_rd = NULL;
			free_str(str);
			str = NULL;
		}
		if (list->next == NULL)
		{
			if (open_rd != NULL)
				ft_lstadd_back(&(info->cmd_list), open_rd);
			if (str != NULL)
				ft_lstadd_back(&(info->cmd_list), ft_lstnew("word", lst_to_arr(str)));
			if (close_rd != NULL)
				ft_lstadd_back(&(info->cmd_list), close_rd);
			
			open_rd = NULL;
			close_rd = NULL;
			free_str(str);
			str = NULL;
		}
			
		list = list->next;
	}
	
}