/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:47:22 by paolives          #+#    #+#             */
/*   Updated: 2021/10/31 14:43:29 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	a;

	a = ft_strlen(src);
	if (size <= 0)
		return (a);
	while (*src && size - 1 > 0)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (a);
}
