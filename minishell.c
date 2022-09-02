/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:58:52 by paolives          #+#    #+#             */
/*   Updated: 2022/08/28 20:42:59 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// после запуска программы он выведет строку "my_shell->" и будет
// ждать ввода и выведет введенную строку в терминал

int	main(int argc, char **argv, char **env)
{
	char	*a;
	t_info	*info;
	t_list	*ptr;
	int		i;

	i = 0;
	if (argc != 1)
	{
		write_error("Wrong number of arguments");
	}
	info = make_info(env);
	while (a = readline("my_shell->"))
	{
		if (a == NULL)
			return (0);
		else if (*a == '\0')
			free(a);
		else
		{
			add_history(a);
			lexer(a, info);
			//parcer(info);
			ptr = info->start;
			while (ptr)
			{
				printf("%s %s\n", ptr->key, ptr->value);
				ptr = ptr->next;
			}
			ptr = NULL;
			free(a);
			free_list(info->start, 1);
			info->start = NULL;
		}
	}
	free_list(info->env_list, 2);
	free(info);
	return (0);
}