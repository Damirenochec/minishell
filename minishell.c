/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:58:52 by paolives          #+#    #+#             */
/*   Updated: 2022/09/10 09:34:13 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// после запуска программы он выведет строку "my_shell->" и будет
// ждать ввода и выведет введенную строку в терминал

char	*write_error(char *error)
{
	printf("%s\n", error);
	return (NULL);
}

void print_mass(char **str)
{
	while (*str)
	{
		printf("mass %s\n", *str);
		str++;
	}
	
}

int	main(int argc, char **argv, char **env)
{
	char	*a;
	t_info	*info;
	t_list	*ptr;
	t_list	*list;
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
			parcer(info);
			
			
			list = info->cmd_list;
			while (list)
			{
				if (get_type_tokken(list->key) == 6)
					print_mass(list->value);
				else
					printf("tokken %s %s\n", list->key, list->value);
				list = list->next;
			}
			free(a);
			free_list(info->start);
			free_cmd(info->cmd_list);
		}
	}
	free_env(info->env_list);
			free(info);
	return (0);
}
