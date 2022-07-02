/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 21:38:25 by paolives          #+#    #+#             */
/*   Updated: 2022/01/24 20:57:54 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(int fd, char *buf, char *str)
{
	ssize_t	byte_was_read;
	char	*s;

	byte_was_read = read(fd, buf, 100);
	while (byte_was_read > 0)
	{
		buf[byte_was_read] = '\0';
		if (!str)
			str = ft_strdup("");
		s = ft_strjoin(str, buf);
		free(str);
		str = s;
		if (ft_strchr(buf, '\n'))
			break ;
		byte_was_read = read(fd, buf, 100);
	}
	return (str);
}

static char	*return_line(char **str)
{
	char	*out;
	char	*con;
	size_t	len;

	len = 0;
	out = NULL;
	while ((*str)[len] != '\n' && (*str)[len])
		len++;
	if ((*str)[len] == '\n')
	{
		out = ft_substr(*str, 0, len + 1);
		con = ft_strdup(*str + len + 1);
		free(*str);
		*str = con;
		if (!**str)
		{
			free(*str);
			*str = NULL;
		}
		return (out);
	}
	out = ft_strdup(*str);
	free(*str);
	*str = NULL;
	return (out);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str;

	if (fd < 0 || 100 <= 0)
		return (NULL);
	buf = malloc(100 + 1);
	if (!buf)
		return (NULL);
	str = ft_read(fd, buf, str);
	free(buf);
	if (!str)
		return (NULL);
	return (return_line(&str));
}
