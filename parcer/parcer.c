/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:36:22 by paolives          #+#    #+#             */
/*   Updated: 2022/07/02 19:54:31 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// после запуска программы он выведет строку "my_shell->" и будет
// ждать ввода и выведет введенную строку в терминал

int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	else
		return (0);
}

void	clear_space(char **str)
{
	int	start;
	int	end;
	char *ptr;

	ptr = *str;
	end = ft_strlen(ptr) - 1;
	start = 0; 
	while(is_space(ptr[end]))
	{
		end--;
	}
	while(is_space(ptr[start]))
		start++;
	*str = ft_substr(ptr, start, end - start + 1);
	free(ptr);
}

char	*ft_slash(char *str, int *i)
{
	char	*tmp;
	char	*tmp2;
	char	*ptr;

	tmp = ft_substr(str, 0, *i);
	tmp2 = ft_strdup(str + *i + 1);
	ptr = tmp;
	tmp = ft_strjoin(tmp, tmp2);
	free(ptr);
	//free(str);
	free(tmp2);
	++(*i);
	return(tmp);
}

char    *write_error(char *str)
{
	printf("%s\n", str);
	return (NULL);
}

char    *ft_double_gap(char *str, int *i)
{
	int     j;
	char    *ptr;
	char    *tmp;
	char    *tmp2;
	char    *tmp3;

	j = *i;
	while(str[++(*i)])
		{
			if (str[*i + 1] == '$')
				str = ft_slash(str, i);
			if (str[*i] == '\"')
				break;
		}
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
	//free(str);
	return(tmp);
}

char    *ft_gap(char *str, int *i)
{
	int     j;
	char    *ptr;
	char    *tmp;
	char    *tmp2;
	char    *tmp3;

	j = *i;
	while(str[++(*i)])
	{
		if (str[*i] == '\'')
			break;
		else if (str[*i] != '\'' && str[*i + 1] == '\0')
			return (write_error("my_sh: alone gap"));
	}
	
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
	//free(str);
	return(tmp);
}

void    parcer(char **str)
{
	// "", '', $, |, >, >>, <
	int i;

	i = -1;
	clear_space(str);
	while(*str[++i])
	{
		if (*str[i] == '\'')
			{
				*str = ft_gap(*str, &i);
				if (str == NULL)
					exit(1);
			}
		else if (*str[i] == '\"')
			*str = ft_double_gap(*str, &i);
	}
}