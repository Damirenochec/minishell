/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:27:51 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/08/19 06:17:02 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*begin;

	if (!lst || !del)
		return ;
	begin = *lst;
	while (begin)
	{
		temp = begin;
		begin = begin->next;
		del(temp->key);
		free(temp);
	}
	*lst = NULL;
}
