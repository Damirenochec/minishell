/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:58:52 by paolives          #+#    #+#             */
/*   Updated: 2022/08/24 05:15:03 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// после запуска программы он выведет строку "my_shell->" и будет
// ждать ввода и выведет введенную строку в терминал

int	main(int argc, char **argv, char **env)
{
	char	*a;
	t_info	*info;

	if (argc != 1)
	{
		write_error("Wrong number of arguments");
	}
	info = make_info(env);
	while ((a = readline("my_shell->")))
	{
		if (a == NULL)
			return (0);
		else if (*a == '\0');
		else
		{
			add_history(a);
			lexer(a, info);
			//parcer(info);
			free(a);
			free_info(info);
		}
	}
	free(info);
	return (0);
}