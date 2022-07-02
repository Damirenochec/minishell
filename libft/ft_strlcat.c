/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:31:24 by paolives          #+#    #+#             */
/*   Updated: 2021/10/31 18:13:27 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	dst = dst + dstlen;
	if (dstlen >= dstsize)
		return (dstsize + srclen);
	while (*src && dstsize - dstlen - 1 > 0)
	{
		*dst++ = *src++;
		dstsize--;
	}
	*dst = '\0';
	return (dstlen + srclen);
}
