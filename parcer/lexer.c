/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:11:39 by paolives          #+#    #+#             */
/*   Updated: 2022/07/26 10:20:38 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*write_error(char *error)
{
	printf("%s\n", error);
	return(NULL);
}

void	add_tokken(char *key, char *value, t_info *info)
{
	t_list *list;
	t_list *ptr;

	list = malloc(sizeof(t_list));
	list->key = key;
	list->value = value;
	list->next = NULL;
	ptr = list;
	if (info->start == NULL)
	{
		info->start = list;
	}
	else
	{
		ptr = info->start;
		while (ptr->next)
		{
			ptr = ptr->next;
		}
		ptr->next = list;
		
	}
}

void	lexer(char *str, t_info *info)
{
	int i;
	int j;

	str = ft_strtrim(str, " \t\n\v\f\r");
	i = -1;
	while(str[++i]) {
		if (str[i] == '|')
			add_tokken("|", NULL, info);
		else if (str[i] == '>')
		{
			if (str[i + 1] == '>')
			{
				add_tokken(">>", NULL, info);
				i++;
			}
			else
				add_tokken(">", NULL, info);
		}
		else if (str[i] == '<')
		{
			if (str[i + 1] == '<')
			{
				add_tokken("<<", NULL, info);
				i++;
			}
			else
				add_tokken("<", NULL, info);
		}
		else if (str[i] == '\'')
		{
			j = i;
			while (str[++i])
			{
				if (str[i] == '\'')
					break;
				else if (str[i + 1] == '\0')
				{
					break;
				}
			}
			add_tokken("word", ft_substr(str, j + 1, i - j - 1), info);
		}
		else if (str[i] == '\"')
		{
			j = i;
			while (str[++i])
			{
				if (str[i] == '\"')
					break;
				else if (str[i + 1] == '\0')
				{
					break;
				}
			}
			add_tokken("word", ft_substr(str, j + 1, i - j - 1), info);
		}
		else if (str[i] == '$')
		{
			j = i;
			if (str[i + 1] == '?')
				add_tokken("$?", NULL, info);
			else
			{
				while (str[++i])
					if (str[i] == '_' || ft_isalnum(str[i] == 0) || str[i] == '$' || str[i] == ' ')
						break;
				if (i == j + 1)
				{
					i = j;
					add_tokken("word", "$", info);
				}
				else
					add_tokken("$", ft_substr(str, j + 1, i - j - 1), info);
			}
		}
		else if (str[i] == ' ' || str[i] == '\t')
		{}
		else
		{
			j = i;
			while (str[i++])
			{
				if (str[i] == '>' || (str[i] == '>' && str[i + 1] == '>') || str[i] == '<' || (str[i] == '<' && str[i + 1] == '<') || str[i] == '|' || str[i] == '$' || str[i] == '\'' || str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
				{
					add_tokken("word", ft_substr(str, j, i - j), info);
					i--;
					break;
				}
			}
		}
	}
	// while (info->start != NULL)
	// {
	// 	printf("%s %s\n", info->start->key, info->start->value);
	// 	info->start = info->start->next;
	// }
	
}