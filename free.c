/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:23:54 by paolives          #+#    #+#             */
/*   Updated: 2022/09/12 17:28:34 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	free_list(t_list *list)
{
	t_list	*ptr;

	while (list != NULL)
	{
		if (list->value != NULL)
			free(list->value);
		ptr = list;
		list = list->next;
		free(ptr);
	}
}

void	free_env(t_list *list)
{
	t_list	*ptr;

	while (list != NULL)
	{
		free(list->key);
		free(list->value);
		ptr = list;
		list = list->next;
		free(ptr);
	}
}

void	free_cmd(t_list *list)
{
	t_list	*ptr;

	while (list)
	{
		ptr = list;
		if (get_type_tokken(list->key) == 6)
			free(list->value);
		list = list->next;
		free(ptr);
	}
}

void	free_str(t_list *list)
{
	t_list	*ptr;

	while (list)
	{
		ptr = list;
		free(ptr);
		list = list->next;
	}
}
