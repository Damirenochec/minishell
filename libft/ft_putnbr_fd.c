/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:51:35 by paolives          #+#    #+#             */
/*   Updated: 2021/11/03 01:56:52 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_recurs(long a, int fd)
{
	long	an;

	if (a > 0)
	{
		ft_recurs(a / 10, fd);
		an = a % 10 + 48;
		write(fd, &an, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	n1;

	n1 = (long)n;
	if (n1 == 0)
		write(fd, "0", 1);
	if (n1 > 0)
		ft_recurs(n1, fd);
	if (n1 < 0)
	{
		write(fd, "-", 1);
		n1 = -n1;
		ft_recurs(n1, fd);
	}
}
