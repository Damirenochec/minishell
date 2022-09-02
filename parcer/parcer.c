/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:36:22 by paolives          #+#    #+#             */
/*   Updated: 2022/09/01 19:27:35 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	parcer(t_info *info)
{
	while (info->start)
	{
		t_list	*ptr;
		void	*arg;

		if (ft_strncmp(info->start->key, "space", 5));
		if (ft_strncmp(info->start->key, "|", 1))
			ft_lstadd_back(&(info->cmd_list), ft_lstnew(info->start->key, NULL));
		if (ft_strncmp(info->start->key, "<", 1))
			if (ft_strncmp(info->start->next->key, "word", 4))
				ft_lstadd_back(&(info->cmd_list), ft_lstnew(info->start->key, info->start->next->value));
			else
				write_error("unexpected tokken");
		if (ft_strncmp(info->start->key, "word", 4))
			if (ft_strncmp(info->start->next->key, "<", 1)
				|| ft_strncmp(info->start->next->key, "<<", 2))
			{
				ft_lstadd_back(&(info->cmd_list), ft_lstnew(info->start->next->key, info->start->value));
			}
			else
			{
				while (ft_strncmp(info->start->key, "word", 4))
				{
					
				}
				
			}
		else
		{
			printf("");
		}
		info->start = info->start->next;
	}
	
	
}