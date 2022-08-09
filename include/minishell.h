/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:19:02 by paolives          #+#    #+#             */
/*   Updated: 2022/07/26 10:15:06 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
//#include <io.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "../libft/libft.h"


// typedef int (&t_builtin_ptr)(t_llist, t_info);
// typedef struct s_info
// {
//     t_builtin_ptr   builtins[7];
//     char            reserved_words[7];
//     char            **envp;
//     t_llist         envp_list;
//     int             envp_flag;
//     char            exit_t;
//     int             status;
    
// }   t_info;




typedef struct s_list
{
	char			*key;
	char			*value;
	struct s_list	*next;
}	t_list;

typedef struct s_info
{
	char	*entered_command;
	t_list	*start;
	char	**env;
}	t_info;

// lexer.c

char	*write_error(char *error);
void	add_tokken(char *key, char *value, t_info *info);
void	lexer(char *str, t_info *info);

// parcer.c

void	parcer(t_info *info);

#endif