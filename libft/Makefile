# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmoshe <gmoshe@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/16 02:45:09 by gmoshe            #+#    #+#              #
#    Updated: 2020/08/31 18:55:46 by gmoshe           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRC		=	ft_isprint.c \
			ft_memset.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_bzero.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_strlcat.c \
			ft_substr.c \
			ft_calloc.c \
			ft_memccpy.c \
			ft_putendl_fd.c \
			ft_strlcpy.c \
			ft_tolower.c \
			ft_isalnum.c \
			ft_memchr.c \
			ft_putstr_fd.c \
			ft_strmapi.c \
			ft_toupper.c \
			ft_isalpha.c \
			ft_memcmp.c \
			ft_split.c \
			ft_strncmp.c \
			ft_isascii.c \
			ft_memcpy.c \
			ft_strchr.c \
			ft_strnstr.c \
			ft_strlen.c \
			ft_isdigit.c \
			ft_memmove.c \
			ft_strdup.c \
			ft_strrchr.c \
			ft_atoi.c \
			ft_putnbr_fd.c \
			ft_printf.c\
			chek.c\
			flag_xp.c\
			ft_itoa_u.c\
			ft_str.c\
			flag_c.c\
			flag_p.c\
			flag_for.c\
			chekker_flags.c\
			get_next_line_utils.c\
			get_next_line.c\

OBJS	=	$(SRC:.c=.o)

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror 

all:	$(NAME)

%.o : %.c
		gcc $(CFLAGS) -c $< -o $@

$(NAME) :	$(OBJS)
		ar rc $(NAME) $^
		ranlib $(NAME)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re		:	fclean all
