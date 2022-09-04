# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paolives <paolives@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 12:29:29 by paolives          #+#    #+#              #
#    Updated: 2022/09/04 08:43:41 by paolives         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

SRCS	=	minishell.c parcer/lexer.c parcer/parcer.c parcer/parce_tokken.c parcer/parce_dollar.c src.c stringsthings.c

OBJ		=	$(SRCS:%.c=%.o)

LIB		=	libft/libft.a

LIBPATH	=	libft/

INCLUDE	=	include/

HEADER	=	minishell.h

CC = gcc

FLAGS	=	-g #-Wall -Wextra -Werror 

RM		= rm -rf


.PHONY:		all	clean	fclean	re libft

all:		libft $(NAME)

libft:
		@$(MAKE) -C $(LIBPATH)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -lreadline $(OBJ) $(LIB) -o $(NAME)

%.o:		%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)


clean:
	make clean -C $(LIBPATH)
	rm -rf $(OBJ) 

fclean:	clean
	make fclean -C $(LIBPATH)
	$(RM) $(NAME)

re: fclean all
