/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 22:11:41 by paolives          #+#    #+#             */
/*   Updated: 2021/11/03 01:36:38 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	a;
	int					neg;

	neg = 1;
	a = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		a = (a * 10) + (*str - '0');
		str++;
	}
	if (neg == 1 && a >= 9223372036854775807)
		return (-1);
	if (neg == -1 && a > 9223372036854775807)
		return (0);
	return (a * neg);
}
