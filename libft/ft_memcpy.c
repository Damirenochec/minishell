/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:15:48 by paolives          #+#    #+#             */
/*   Updated: 2021/11/03 01:42:04 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*nsrc;
	char	*ndst;
	size_t	count;

	nsrc = (char *) src;
	ndst = (char *) dst;
	count = 0;
	if (!nsrc && !ndst)
		return (NULL);
	while (count < n)
	{
		*ndst = *nsrc;
		ndst++;
		nsrc++;
		count++;
	}
	return (dst);
}
