/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:48:34 by paolives          #+#    #+#             */
/*   Updated: 2022/08/24 05:14:21 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

char	*write_error(char *error)
{
	printf("%s\n", error);
	return (NULL);
}

void	free_info(t_info *info)
{
	t_list	*ptr;
	while (info->start)
	{
		ptr = info->start;
		info->start = info->start->next;
		if (ptr->value != NULL)
			free(ptr->value);
		free(ptr);
	}
	while (info->env_list)
	{
		ptr = info->env_list;
		info->env_list = info->env_list->next;
		if (ptr->value != NULL)
		{
			free(ptr->key);
			free(ptr->value);
		}
		free(ptr);
	}
}

void	parce_env(t_info *info)
{
	char	**envp;
	char	*str;
	int		index;
	char	*key;
	char	*value;
	
	envp = info->env;
	while (*envp)
	{
		str = *envp;
		index = 0;
		while (*str)
		{
			if (*str == '=')
				break;
			str++;
			index++;
		}
		key = ft_substr(*envp, 0, index);
		value = ft_substr(*envp, index + 1, ft_strlen(*envp));
		ft_lstadd_back(&(info->env_list), ft_lstnew(key, value));
		envp++;
	}
	
}

t_info	*make_info(char **env)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
	{
		printf("malloc error\n");
		return (0);
	}
	info->env = env;
	info->env_list = NULL;
	parce_env(info);
	info->start = NULL;
}

void	*envp_search(char *str, t_list *list)
{
	while (list)
	{
		if (ft_strncmp(str, list->key, ft_strlen(str)) == 0)
			return(list->value);
		list = list->next;
		return(NULL);
	}
	
}

int	ft_strichr(const char *s, int c)
{
	int	a;

	a = 0;
	while (c > 127)
		c = c - 128;
	while (*s)
	{
		if (*s == c)
			return (a);
		a++;
		s++;
	}
	return (-1);
}

char	*cutsubstr(char *str, int cut, int end)
{
	char	*pre;
	char	*post;

	pre = ft_substr(str, 0, cut);
	post = ft_substr(str, end + 1, ft_strlen(str) - end + 1);
	str = ft_strjoin(pre, post);
	free(pre);
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
