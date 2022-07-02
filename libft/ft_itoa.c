/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:42:42 by paolives          #+#    #+#             */
/*   Updated: 2021/11/03 01:54:02 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_intsize(long c)
{
	long	b;

	b = 0;
	if (c < 0)
	{
		b++;
		c = -c;
	}
	while (c / 10 > 0)
	{
		b++;
		c = c / 10;
	}
	return (b);
}

static	char	*ft_set(char *c, long n)
{
	while (n / 10 > 0)
	{
		*c = n % 10 + '0';
		c--;
		n = n / 10;
	}
	*c = n % 10 + '0';
	return (c);
}

char	*ft_itoa(int n)
{
	char	*a;
	long	d;

	d = n;
	a = (char *)ft_calloc((ft_intsize(d) + 2), sizeof(char));
	if (!a)
		return (NULL);
	if (d < 0)
	{
		*a = '-';
		d = -d;
	}
	ft_set (a + ft_intsize(n), d);
	return (a);
}
