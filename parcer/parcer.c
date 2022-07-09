/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:36:22 by paolives          #+#    #+#             */
/*   Updated: 2022/07/09 03:19:11 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// после запуска программы он выведет строку "my_shell->" и будет
// ждать ввода и выведет введенную строку в терминал
char	*write_error(char *error)
{
	printf("%s\n", error);
	return(NULL);
}

char	*ft_gap(char *str, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*ptr;

	j = *i;
	while(str[++(*i)])
		if (str[*i] == '\'')
			break;
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	tmp3 = ft_strdup(str + *i + 1);
	ptr = tmp;
	tmp = ft_strjoin(tmp, tmp2);
	free(ptr);
	ptr = tmp;
	tmp = ft_strjoin(tmp, tmp3);
	free(ptr);
	free(tmp2);
	free(tmp3);
	return(tmp);
}

char	*ft_double_gap(char *str, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*ptr;

	j = *i;
	while(str[++(*i)])
		if (str[*i] == '\"')
			break;
	tmp = ft_substr(str, 0, j);
	tmp2 = ft_substr(str, j + 1, *i - j - 1);
	tmp3 = ft_strdup(str + *i + 1);
	ptr = tmp;
	tmp = ft_strjoin(tmp, tmp2);
	free(ptr);
	ptr = tmp;
	tmp = ft_strjoin(tmp, tmp3);
	free(ptr);
	free(tmp2);
	free(tmp3);
	return(tmp);
}

char	*ft_dollar(char *str, int *i, char **env)
{
	int		j;
	int		l;
	char	*tmp;
	char	*ptr;
	char	*tmp2;
	char	*tmp3;

	j = *i;
	l = -1;
	while(str[++(*i)])
		if (str[*i] == '_' || ft_isalnum(str[*i]) == 0)
			break;
	if (*i == j + 1)
		return (str);
	tmp = ft_substr(str, j + 1, *i - j - 1);
	ptr = tmp;
	tmp = ft_strjoin(tmp, "=");
	free(ptr);
	ptr = tmp;
	while (env[++l])
	{
		if (ft_memcmp(env[l], tmp, ft_strlen(tmp)) == 0)
		{
			free(ptr);
			ptr = tmp;
			tmp = ft_substr(env[l], ft_strlen(tmp), ft_strlen(env[l]));
			free(ptr);
			ptr = tmp;
		}
	}
	tmp2 = ft_substr(str, 0, j);
	tmp = ft_strjoin(tmp2, tmp);
	free(ptr);
	ptr = tmp;
	tmp2 = ft_substr(str, *i, ft_strlen(str));
	tmp = ft_strjoin(tmp, tmp2);
	printf("5 %s\n", tmp);
	return(str);
}

int	preparcer(char *str)
{
	int	i;

	i = -1;
	while(str[++i])
	{
		if (str[i] == '\'')
			str = ft_strchr(str + i + 1, '\'');
		else if (str[i] == '\"')
			str = ft_strchr(str + i + 1, '\"');
		if (str == NULL)
		{
			write_error("my_sh: alone gap");
			return (1);
		}	
	}
	return(0);
}

int	parcer(char *str, char **env)
{
	int	i;
	char	*ptr;
	int flag;

	i = -1;
	flag = preparcer(str);
	if (flag)
		return (1);
	str = ft_strtrim(str, " \t\n\v\f\r");
	ptr = str;
	while(str[++i])
	{
		// ', ", $, >, >>, <
		if (str[i] == '\'')
		{
			ptr = str;
			str = ft_gap(str, &i);
			free(ptr);
		}
		else if (str[i] == '\"')
		{
			ptr = str;
			str = ft_double_gap(str, &i);
			free(ptr);
		}
		else if (str[i] == '$')
		{
			str = ft_dollar(str, &i, env);
		}
	}
	printf("%s\n", str);
	free(str);
	return(0);
}