/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringsthings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 08:33:19 by paolives          #+#    #+#             */
/*   Updated: 2022/08/27 08:46:36 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

char	*cutsubstr(char *str, int cut, int end)
{
	char	*pre;
	char	*post;

	pre = ft_substr(str, 0, cut);
	post = ft_substr(str, end + 1, ft_strlen(str) - end + 1);
	str = ft_strjoin(pre, post);
	if (pre != NULL)
		free(pre);
	if (post != NULL)
		free(post);
	return(str);
}

char	*putsubstr(char *str, int index, char *sub)
{
	char	*pre;
	char	*post;

	pre = ft_substr(str, 0, index);
	post = ft_substr(str, index, ft_strlen(str) - index);
	str = ft_strjoin(pre, sub);
	free(pre);
	pre = str;
	str = ft_strjoin(str, post);
	free(post);
	free(pre);
	return(str);
}

char	*replacesubstr(char *str, int start, int end, char *sub)
{
	char	*ptr;

	str = cutsubstr(str, start, end);
	ptr = str;
	str = putsubstr(str, start, sub);
	free(ptr);
	return(str);
}

