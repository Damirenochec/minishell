/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:29:43 by paolives          #+#    #+#             */
/*   Updated: 2021/11/01 15:44:27 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*ptr1;

	ptr = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ptr1 = ptr;
	while (*s1)
	{
		*ptr++ = *s1++;
	}
	*ptr = '\0';
	return (ptr1);
}
