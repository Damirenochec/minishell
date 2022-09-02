/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:11:39 by paolives          #+#    #+#             */
/*   Updated: 2022/09/01 16:39:50 by paolives         ###   ########.fr       */
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

char	*parce_dollar(char *str, t_info *info)
{
	int		i;
	int		j;
	char	*new_str;
	char	*ptr;
	char	*pid;

	i = -1;
	while (str[++i])
	{
		while (str[i] != '$' && str[i])
			i++;
		if (str[i + 1] == '$' || str[i + 1] == '?')
		{
			if (str[i + 1] == '$')
				new_str = ft_itoa(getpid());
			else if (str[i + 1] == '?')
				new_str = ft_itoa(info->status);
			ptr = str;
			str = replacesubstr(str, i, i + 1, new_str);
			free(new_str);
			free(ptr);
		}
		else if (ft_isdigit(str[i + 1]))
		{
			ptr = str;
			str = cutsubstr(str, i, i + 1);
			free(ptr);
		}
		else if (str[i + 1] == '_' || ft_isalnum(str[i + 1]))
		{
			j = i;
			while (str[i + 1] == '_' || ft_isalnum(str[i + 1]))
				i++;
			new_str = ft_substr(str, j + 1, i - j);
			ptr = new_str;
			new_str = envp_search(new_str, info->env_list);
			free(ptr);
			ptr = str;
			str = replacesubstr(str, j, i, new_str);
			free(ptr);
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
