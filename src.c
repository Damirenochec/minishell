/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:48:34 by paolives          #+#    #+#             */
/*   Updated: 2022/08/19 10:43:19 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

char	*write_error(char *error)
{
	printf("%s\n", error);
	return (NULL);
}

void	free_info(t_info *info)
{
	t_list	*ptr;
	while (info->start)
	{
		ptr = info->start;
		info->start = info->start->next;
		if (ptr->value != NULL)
			free(ptr->value);
		free(ptr);
	}
	free(info);
}

t_info	*make_info(char **env)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
	{
		printf("malloc error\n");
		return (0);
	}
	info->env = env;
	info->start = NULL;
}