# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 19:12:45 by flolefeb          #+#    #+#              #
#    Updated: 2019/11/27 14:57:08 by flolefeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CC 	=	gcc

SRCS	=	ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_strchr.c \
		ft_strncmp.c \
		ft_toupper.c \
		ft_atoi.c \
		ft_memcpy.c \
		ft_strrchr.c \
		ft_memset.c \
		ft_strlen.c \
		ft_tolower.c \
		ft_bzero.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_charset.c \

OBJS	=	$(SRCS:.c=.o)

FLAGS	=	-Wall -Wextra -Werror


HEADER	=	libft.h 

$(NAME)	:	#$(HEADER) $(OBJS)
		$(CC) $(FLAGS) -c $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all	:	$(NAME)

clean	: 
		rm -rf $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all 
