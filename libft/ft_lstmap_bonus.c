/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufitzhug <ufitzhug@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:28:29 by ufitzhug          #+#    #+#             */
/*   Updated: 2021/10/30 23:30:40 by ufitzhug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*elem1;
	t_list	*list1;

	if (!lst || !f)
		return (NULL);
	elem1 = ft_lstnew(f(lst->content));
	if (!elem1)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst)
	{
		list1 = ft_lstnew(f(lst->content));
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
