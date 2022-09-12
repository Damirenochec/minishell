/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 08:36:37 by paolives          #+#    #+#             */
/*   Updated: 2022/09/12 16:46:54 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*parce_exit_status_pid(char *str, int i, t_info *info)
{
	char	*new_str;
	char	*ptr;

	if (str[i + 1] == '$')
		new_str = ft_itoa(getpid());
	else if (str[i + 1] == '?')
		new_str = ft_itoa(info->status);
	ptr = str;
	str = replacesubstr(str, i, i + 1, new_str);
	free(new_str);
	free(ptr);
	return (str);
}

char	*parce_dollar_digit(char *str, int i)
{
	char	*ptr;

	ptr = str;
	str = cutsubstr(str, i, i + 1);
	free(ptr);
	return (str);
}

char	*parce_dollar_env(char *str, int i, t_info *info)
{
	int		j;
	char	*new_str;
	char	*ptr;

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
	return (str);
}

char	*parce_dollar(char *str, t_info *info)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		while (str[i] != '$' && str[i])
			i++;
		if (str[i + 1] == '$' || str[i + 1] == '?')
			str = parce_exit_status_pid(str, i, info);
		else if (ft_isdigit(str[i + 1]))
			str = parce_dollar_digit(str, i);
		else if (str[i + 1] == '_' || ft_isalnum(str[i + 1]))
			str = parce_dollar_env(str, i, info);
	}
	return (str);
}
