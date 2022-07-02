/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:41:17 by paolives          #+#    #+#             */
/*   Updated: 2021/10/26 15:52:36 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*nsrc;
	char	*ndst;
	size_t	count;

	nsrc = (char *)src;
	ndst = (char *)dst;
	count = 0;
	if (!ndst && !nsrc)
		return (NULL);
	while (count < len)
	{
		if (ndst < nsrc)
			ndst[count] = nsrc[count];
		else
			ndst[len - count - 1] = nsrc[len - count - 1];
		count++;
	}
	return (dst);
}
