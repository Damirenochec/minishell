# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paolives <paolives@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 12:29:29 by paolives          #+#    #+#              #
#    Updated: 2022/06/29 02:20:49 by paolives         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	minishell

SRCS	=	parcer.c

OBJ		=	$(SRCS:%.c=%.o)

INCLUDE	=	include/

HEADER	=	minishell.h

FLAGS	=	-Wall -Wextra -Werror 

RM		= rm -rf


.PHONY:		all	clean	fclean	re

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -lreadline $(OBJ) $(LIB) -o $(NAME)

%.o:		%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)


clean:
			@$(RM) $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all
