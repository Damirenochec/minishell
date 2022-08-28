/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 08:48:34 by paolives          #+#    #+#             */
/*   Updated: 2022/08/28 20:32:06 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

char	*write_error(char *error)
{
	printf("%s\n", error);
	return (NULL);
}

void	free_list(t_list *list, int i)
{
	t_list	*ptr;

	while (list != NULL)
	{
		if (i == 2 && list->key != NULL)
			free(list->key);
		if (list->value != NULL)
			free(list->value);
		ptr = list;
		list = list->next;
		ptr->next = NULL;
		free(ptr);
	}
	//list = NULL;
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
	info->status = 0;
}

void	*envp_search(char *str, t_list *list)
{
	while (list)
	{
		if (ft_strncmp(str, list->key, ft_strlen(list->key)) == 0
			&& ft_strlen(str) == ft_strlen(list->key))
			return(list->value);
		list = list->next;
	}
	return("");
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


