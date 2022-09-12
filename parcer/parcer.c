/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:36:22 by paolives          #+#    #+#             */
/*   Updated: 2022/09/12 16:59:25 by paolives         ###   ########.fr       */
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

t_list	*parce_redir(t_list *list, t_list **open_rd, t_list **close_rd)
{
	if (list->next && get_type_tokken(list->next->key) == 6)
	{
		if (get_type_tokken(list->key) == 2 || get_type_tokken(list->key) == 4)
			ft_lstadd_back(open_rd, ft_lstnew(list->key, list->next->value));
		else
			ft_lstadd_back(close_rd, ft_lstnew(list->key, list->next->value));
		list = list->next;
	}
	else
		write_error("syntax error near unexpected token");
	return (list);
}

void	parce_end_cmd(t_info *info, t_list **open_rd,
	t_list **str, t_list **close_rd)
{
	if (*open_rd != NULL)
		ft_lstadd_back(&(info->cmd_list), *open_rd);
	if (*str != NULL)
		ft_lstadd_back(&(info->cmd_list), ft_lstnew("word", lst_to_arr(*str)));
	if (*close_rd != NULL)
		ft_lstadd_back(&(info->cmd_list), *close_rd);
	*open_rd = NULL;
	*close_rd = NULL;
	free_str(*str);
	*str = NULL;
}

t_list	*start_parcer(t_info *info, t_list **open_rd,
	t_list **str, t_list **close_rd)
{
	t_list	*list;

	list = info->start;
	*str = NULL;
	*open_rd = NULL;
	*close_rd = NULL;
	return (list);
}

void	parcer(t_info *info)
{
	t_list	*list;
	t_list	*open_rd;
	t_list	*close_rd;
	t_list	*str;

	list = start_parcer(info, &open_rd, &str, &close_rd);
	if (get_type_tokken(list->key) == 5)
		write_error("syntax error near unexpected token \'|\'");
	while (list)
	{
		if (get_type_tokken(list->key) >= 1 && get_type_tokken(list->key) <= 4)
			list = parce_redir(list, &open_rd, &close_rd);
		else if (get_type_tokken(list->key) == 6)
			ft_lstadd_back(&str, ft_lstnew(list->key, list->value));
		if (get_type_tokken(list->key) == 5 || list->next == NULL)
		{
			if (!list->next && get_type_tokken(list->key) == 5)
				write_error("syntax error near unexpected token");
			parce_end_cmd(info, &open_rd, &str, &close_rd);
			if (get_type_tokken(list->key) == 5)
				ft_lstadd_back(&(info->cmd_list), ft_lstnew("|", NULL));
		}
		list = list->next;
	}
}
