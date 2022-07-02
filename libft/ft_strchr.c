/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:45:57 by paolives          #+#    #+#             */
/*   Updated: 2021/11/03 01:44:21 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*a;

	while (c > 127)
		c = c - 128;
	while (*s)
	{
		if (*s == c)
		{
			a = (char *)s;
			return (a);
		}
		s++;
	}
	if (*s == c)
	{
		a = (char *)s;
		return (a);
	}
	return (NULL);
}
