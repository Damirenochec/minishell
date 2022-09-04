/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_tokken.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 08:17:26 by paolives          #+#    #+#             */
/*   Updated: 2022/09/04 08:58:43 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	parce_quotes(char *quotes, char *str, int i, t_info *info)
{
	int		j;
	char	*new_str;
	char	*ptr;

	j = i;
	while (str[++i])
	{
		if (str[i] == *quotes)
			break ;
		else if (str[i + 1] == '\0')
		{
			write_error("alone gap");
			ft_lstadd_back(&(info->start), ft_lstnew("word", NULL));
			return (j);
		}
	}
	new_str = ft_substr(str, j + 1, i - j - 1);
	if (*quotes == '\"')
		new_str = parce_dollar(new_str, info);
	ft_lstadd_back(&(info->start), ft_lstnew("word", new_str));
	return (i);
}

int	parce_angle_brackets(char *brackets, char *str, int i, t_info *info)
{
	if (ft_strncmp(str + i, "<<", 2) == 0)
	{
		ft_lstadd_back(&(info->start), ft_lstnew("<<", NULL));
		i++;
	}
	else if (ft_strncmp(str + i, ">>", 2) == 0)
	{
		ft_lstadd_back(&(info->start), ft_lstnew(">>", NULL));
		i++;
	}
	else
		ft_lstadd_back(&(info->start), ft_lstnew(brackets, NULL));
	return (i);
}

int	parce_word(char *str, int i, t_info *info)
{
	int		j;
	char	*new_str;
	char	*ptr;

	j = i;
	while (str[i++])
	{
		if (str[i] == '>' || (str[i] == '>' && str[i + 1] == '>')
			|| str[i] == '<' || (str[i] == '<' && str[i + 1] == '<')
			|| str[i] == '|' || str[i] == '\'' || str[i] == '\"'
			|| str[i] == '\t' || str[i] == '\0' || str[i] == '\n'
			|| str[i] == ' ')
		{
			new_str = ft_substr(str, j, i - j);
			ptr = new_str;
			new_str = parce_dollar(new_str, info);
			ft_lstadd_back(&(info->start), ft_lstnew("word", new_str));
			i--;
			break ;
		}
	}
	return (i);
}

int	parce_space(char *str, int i, t_info *info)
{
	while (str[i++] == ' ')
	{
	}
	ft_lstadd_back(&(info->start), ft_lstnew("space", NULL));
	i -= 2;
	return (i);
}
