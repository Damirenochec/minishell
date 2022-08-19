/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:11:39 by paolives          #+#    #+#             */
/*   Updated: 2022/08/19 10:29:30 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	add_tokken(char *key, char *value, t_info *info)
{
	ft_lstadd_back(&(info->start), ft_lstnew(key, value));
}

int	parce_quotes(char *quotes, char *str, int i, t_info *info)
{
	int	j;

	j = i;
	while (str[++i])
	{
		if (str[i] == *quotes)
			break ;
		else if (str[i + 1] == '\0')
		{
			write_error("alone gap");
			add_tokken(quotes, NULL, info);
			return (j);
		}
	}
	add_tokken(quotes, ft_substr(str, j + 1, i - j - 1), info);
	return (i);
}

int	parce_angle_brackets(char *brackets, char *str, int i, t_info *info)
{
	if (ft_strncmp(str + i, "<<", 2) == 0)
	{
		add_tokken("<<", NULL, info);
		i++;
	}
	else if (ft_strncmp(str + i, ">>", 2) == 0)
	{
		add_tokken(">>", NULL, info);
		i++;
	}
	else
		add_tokken(brackets, NULL, info);
	return (i);
}

int	parce_word(char *str, int i, t_info *info)
{
	int	j;

	j = i;
	while (str[i++])
	{
		if (str[i] == '>' || (str[i] == '>' && str[i + 1] == '>')
			|| str[i] == '<' || (str[i] == '<' && str[i + 1] == '<')
			|| str[i] == '|' || str[i] == '$' || str[i] == '\''
			|| str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
		{
			add_tokken("word", ft_substr(str, j, i - j), info);
			i--;
			break ;
		}
	}
	return (i);
}

void	lexer(char *str, t_info *info)
{
	int	i;
	int	j;

	str = ft_strtrim(str, " \t\n\v\f\r");
	i = -1;
	while (str[++i])
	{
		if (str[i] == '|')
			add_tokken("|", NULL, info);
		else if (str[i] == '>')
			i = parce_angle_brackets(">", str, i, info);
		else if (str[i] == '<')
			i = parce_angle_brackets("<", str, i, info);
		else if (str[i] == '\'')
			i = parce_quotes("\'", str, i, info);
		else if (str[i] == '\"')
			i = parce_quotes("\"", str, i, info);
		else if (str[i] == ' ')
		{
			while (str[i++] == ' ');
			add_tokken("space", NULL, info);
			i -= 2;
		}
		else
			i = parce_word(str, i, info);
	}
	free_info(info);
	free(str);
}
