/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:36:46 by paolives          #+#    #+#             */
/*   Updated: 2021/11/02 13:03:56 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 1)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		n--;
	}
	if (*str == (unsigned char)c && n > 0)
		return (str);
	return (NULL);
}
