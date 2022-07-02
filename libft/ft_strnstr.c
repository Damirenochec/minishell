/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:14:46 by paolives          #+#    #+#             */
/*   Updated: 2021/10/31 22:07:05 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	i;
	size_t	l;

	a = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[a])
	{
		i = 0;
		if (haystack[a] == needle[i])
		{
			l = 0;
			while (haystack[a + i] == needle[i] && len > i + a)
			{
				if (!needle[i + 1])
					return ((char *)haystack + a);
				l++;
				i++;
			}
		}
		a++;
	}
	return (NULL);
}
