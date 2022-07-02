/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:29:51 by paolives          #+#    #+#             */
/*   Updated: 2021/11/03 00:00:31 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <fcntl.h>

static	int	ft_wordscount(char const *s, char c)
{
	int	w;

	w = 0;
	while (*s)
	{
		if ((*s != c && *(s + 1) == c) || (*s != c && *(s + 1) == '\0'))
			w++;
		s++;
	}
	return (w);
}

static int	ft_findw(char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	return (len);
}

static void	*ft_freestr(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
	return (NULL);
}

static char	**ft_wordsplit( char **str, char const *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = ft_findw((char *)(s + i), c);
			str[j] = ft_substr((s + i), 0, len);
			if (!str[j])
				ft_freestr(str, j);
			i = i + len - 1;
			j++;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc((ft_wordscount(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	return (ft_wordsplit(str, s, c));
}
