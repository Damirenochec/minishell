/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:58:52 by paolives          #+#    #+#             */
/*   Updated: 2022/07/26 10:15:29 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// после запуска программы он выведет строку "my_shell->" и будет
// ждать ввода и выведет введенную строку в терминал

int	main(int argc, char **argv, char **env)
{
	t_info *info;
	t_list *list;
	char	*a;

	if (argc != 1)
	{
		write_error("Wrong number of arguments");
	}
	info = malloc(sizeof(t_info));
	if (!info)
	{
		printf("malloc error\n");
		return (0);
	}
	info->env = env;
	info->start = NULL;
	list = info->start;
	while ((a = readline("my_shell->")))
	{
		if (a == NULL)
			return (0);
		else if (*a == '\0');
		else
		{
			add_history(a);
			info->entered_command = a;
			lexer(a, info);
			parcer(info);
			free(a);
		}	
	}
	return (0);
}