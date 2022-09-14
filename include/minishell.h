/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolives <paolives@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:19:02 by paolives          #+#    #+#             */
/*   Updated: 2022/09/14 15:04:12 by paolives         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
//#include <io.h>
# include<readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "../libft/libft.h"
# define SUCCESS 0
# define ERROR 1
# define PATH_MAX 4096

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
	int		status;
}	t_info;

//parce_dollar.c

char	*parce_exit_status_pid(char *str, int i, t_info *info);
char	*parce_dollar_digit(char *str, int i);
char	*parce_dollar_env(char *str, int i, t_info *info);
char	*parce_dollar(char *str, t_info *info);

//parce_tokken.c
int		parce_quotes(char *quotes, char *str, int i, t_info *info);
int		parce_angle_brackets(char *brackets, char *str, int i, t_info *info);
int		parce_word(char *str, int i, t_info *info);
int		parce_space(char *str, int i, t_info *info);

// lexer.c
void	lexer(char *str, t_info *info);

// parcer.c
char	**lst_to_arr(t_list *list);
t_list	*parce_redir(t_list *list, t_list **open_rd, t_list **close_rd);
void	parce_end_cmd(t_info *info, t_list **open_rd,
			t_list **str, t_list **close_rd);
t_list	*start_parcer(t_info *info, t_list **open_rd,
			t_list **str, t_list **close_rd);
void	parcer(t_info *info);

//free.c
void	free_list(t_list *list);
void	free_env(t_list *list);
void	free_cmd(t_list *list);
void	free_str(t_list *list);

// src.c
t_info	*make_info(char **env);
char	*write_error(char *error);
void	*envp_search(char *str, t_list *list);
int		get_type_tokken(char *tokken);

// stringsthings.c
char	*cutsubstr(char *str, int cut, int end);
char	*putsubstr(char *str, int index, char *sub);
char	*replacesubstr(char *str, int start, int end, char *sub);
void	concatenation_strings(t_info *info);
void	delite_space(t_info *info);

// executor
void	executor(t_list *cmd_list);
size_t	ft_has_builtin(t_list *cmd_list);

// built-ins
void	ft_exec_builtin(t_list *cmd_list);
int		ft_echo(t_list *cmd_list);
int		ft_pwd(void);

//minishell.c
void	my_sig_ctrl_c(int i);

#endif