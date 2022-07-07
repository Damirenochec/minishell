/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:58:52 by paolives          #+#    #+#             */
/*   Updated: 2022/07/04 18:16:46 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// после запуска программы он выведет строку "my_shell->" и будет
// ждать ввода и выведет введенную строку в терминал

int	main(int argc, char **argv, char **env)
{
	char	*a;

	if (argc != 1)
	{
		write_error("Wrong number of arguments");
	}
	while ((a = readline("my_shell->$")))
	{
		if (a == NULL)
			return (0);
		else if (*a == '\0');
		else
		{
			add_history(a);
			parcer(a, env);
			free(a);
		}
	}
	return (0);
}