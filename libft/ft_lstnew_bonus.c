/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 00:28:48 by ufitzhug          #+#    #+#             */
/*   Updated: 2022/08/19 06:14:15 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *key, void *value)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(*new_elem));
	if (!new_elem)
		return (NULL);
	new_elem->key = key;
	new_elem->value = value;
	new_elem->next = NULL;
	return (new_elem);
}
