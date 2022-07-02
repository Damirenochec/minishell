/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:22:50 by paolives          #+#    #+#             */
/*   Updated: 2021/11/03 01:41:19 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	count;
	char	*a;

	a = (char *) b;
	count = 0;
	while (count < len)
	{
		*a = c;
		a++;
		count++;
	}
	return (b);
}
