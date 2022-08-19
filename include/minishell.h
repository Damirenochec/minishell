/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:19:02 by paolives          #+#    #+#             */
/*   Updated: 2022/08/19 10:58:29 by paolives         ###   ########.fr       */
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

typedef struct s_info
{
	t_list	*start;
	t_list	*cmd_list;
	char	**env;
	t_list	*env_list;
}	t_info;

// lexer.c
int		parce_quotes(char *quotes, char *str, int i, t_info *info);
int		parce_angle_brackets(char *brackets, char *str, int i, t_info *info);
int		parce_word(char *str, int i, t_info *info);
int		parce_space(char *str, int i, t_info *info);
void	lexer(char *str, char **env);

// parcer.c

void	parcer(t_info *info);

// src.c

t_info	*make_info(char **env);
char	*write_error(char *error);
void	free_info(t_info *info);


#endif