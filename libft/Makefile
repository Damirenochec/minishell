# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paolives <paolives@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 09:04:28 by paolives          #+#    #+#              #
#    Updated: 2022/06/30 13:38:38 by paolives         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
#
SRCS	=	ft_bzero.c		ft_isalnum.c	ft_isalpha.c\
			ft_isascii.c	ft_isdigit.c	ft_isprint.c\
			ft_memcpy.c		ft_memmove.c	ft_memset.c\
			ft_strlcpy.c	ft_strlen.c		ft_toupper.c\
			ft_tolower.c	ft_strchr.c		ft_strrchr.c\
		   	ft_strncmp.c	ft_memchr.c		ft_memcmp.c\
			ft_strlcat.c	ft_strnstr.c	ft_atoi.c\
			ft_calloc.c		ft_strdup.c		ft_substr.c\
			ft_strjoin.c	ft_strtrim.c	ft_strmapi.c\
			ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c\
			ft_putendl_fd.c	ft_itoa.c		ft_split.c\
			ft_putnbr_fd.c	get_next_line.c
#
HEADER = libft.h
OBJ = $(patsubst %.c, %.o, $(SRCS))
#
CC	=	gcc
CFLAGS = -Wall -Wextra -Werror 
#
.PHONY : all clean fclean re
#
all	: $(NAME)
#
$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $?
#
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
#
clean	:
	rm -f $(OBJ) $(OBJ_B)
#
fclean	: clean
	$(RM) $(NAME)
#
re	:	fclean all
