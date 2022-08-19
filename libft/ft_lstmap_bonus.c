/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:28:29 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/08/19 06:24:47 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem1;
	t_list	*list1;

	if (!lst || !f)
		return (NULL);
	elem1 = ft_lstnew(f(lst->key), f(lst->value));
	if (!elem1)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		list1 = ft_lstnew(f(lst->key), f(lst->value));
		if (!list1)
		{
			ft_lstclear(&list1, del);
			return (NULL);
		}
		ft_lstadd_back(&elem1, list1);
		lst = lst->next;
	}
	return (elem1);
}
