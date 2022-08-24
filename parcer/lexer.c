/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:11:39 by paolives          #+#    #+#             */
/*   Updated: 2022/08/24 05:18:42 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	parce_quotes(char *quotes, char *str, int i, t_info *info)
{
	int		j;
	char	*new_str;

	j = i;
	while (str[++i])
	{
		if (str[i] == *quotes)
			break ;
		else if (str[i + 1] == '\0')
		{
			write_error("alone gap");
			ft_lstadd_back(&(info->start), ft_lstnew(quotes, NULL));
			return (j);
		}
	}
	str = ft_substr(str, j + 1, i - j - 1);
	parce_dollar(str, info);
	ft_lstadd_back(&(info->start), ft_lstnew(quotes, str));
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

	j = i;
	while (str[i++])
	{
		if (str[i] == '>' || (str[i] == '>' && str[i + 1] == '>')
			|| str[i] == '<' || (str[i] == '<' && str[i + 1] == '<')
			|| str[i] == '|' || str[i] == '\'' || str[i] == '\"'
			|| str[i] == '\t' || str[i] == '\0' || str[i] == '\n')
		{
			new_str = ft_substr(str, j, i - j);
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

char	*parce_dollar(char *str, t_info *info)
{
	int		i;
	char	*new_str;
	char	*ptr;
	char	*pid;

	while (ft_strichr(str, '$') != -1)
	{
		i = ft_strichr(str, '$');
		if (i == -1)
			return (str);
		if (*(str + i + 1) == '$' || *(str + i + 1) == '?')
		{
			ptr = str;
			str = cutsubstr(str, i, i + 1);
			free(ptr);
			ptr = str;
			if (*(str + i + 1) == '$')
				pid = ft_itoa(getpid());
			else if (*(str + i + 1) == '?')
				pid = ft_itoa(info->status);
			str = putsubstr(str, i, pid);
			free(pid);
			free(ptr);
			i = 0;
			//printf("%s\n", str);
		}
	}
	return (str);
}

void	lexer(char *str, t_info *info)
{
	int		i;

	str = ft_strtrim(str, " \t\n\v\f\r");
	i = -1;
	while (str[++i])
	{
		if (str[i] == '|')
			ft_lstadd_back(&(info->start), ft_lstnew("|", NULL));
		else if (str[i] == '>')
			i = parce_angle_brackets(">", str, i, info);
		else if (str[i] == '<')
			i = parce_angle_brackets("<", str, i, info);
		else if (str[i] == '\'')
			i = parce_quotes("\'", str, i, info);
		else if (str[i] == '\"')
			i = parce_quotes("\"", str, i, info);
		else if (str[i] == ' ')
			i = parce_space(str, i, info);
		else
			i = parce_word(str, i, info);
	}
	free(str);
}
