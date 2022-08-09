/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:36:22 by paolives          #+#    #+#             */
/*   Updated: 2022/07/26 10:19:56 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	parcer(t_info *info)
{
	if (!ft_memcmp(info->start->value, "echo", 4))
	{
		if (!ft_memcmp(info->start->next->value, "-n", 2))
		{
			info->start = info->start->next->next;
			while (!ft_memcmp(info->start->key, "word", 4))
			{
				printf("%s ", info->start->value);
				if (!info->start->next)
					break;
				info->start = info->start->next;
			}
		}
		else
		{
			info->start = info->start->next;
			while (!ft_memcmp(info->start->key, "word", 4))
			{
				printf("%s ", info->start->value);
				if (!info->start->next)
					break;
				info->start = info->start->next;
			}
			printf("\n");
			
		}
		
	}
}