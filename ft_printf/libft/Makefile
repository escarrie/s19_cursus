# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escarrie <escarrie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 13:58:23 by escarrie          #+#    #+#              #
#    Updated: 2020/01/20 14:24:44 by escarrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	ft_atoi.c			\
			ft_bzero.c			\
			ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_memccpy.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_memcpy.c			\
			ft_memset.c			\
			ft_memmove.c		\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_strchr.c			\
			ft_strlcat.c		\
			ft_strlcpy.c		\
			ft_strlen.c			\
			ft_strncmp.c		\
			ft_strnstr.c		\
			ft_strrchr.c		\
			ft_tolower.c		\
			ft_toupper.c		\
			ft_calloc.c			\
			ft_strdup.c			\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_substr.c			\
			ft_strjoin.c		\
			ft_itoa.c			\
			ft_strtrim.c		\
			ft_split.c			\
			ft_strmapi.c		\

B_SRCS	=	ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\

OBJS	= ${SRCS:.c=.o}

B_OBJS	= ${B_SRCS:.c=.o}

NAME	= libft.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rc $(NAME) ${OBJS}
			ranlib $(NAME)

all:		$(NAME)

clean:		
			${RM} ${OBJS} ${B_OBJS}

fclean:		clean
			${RM} $(NAME)

re:			fclean all

bonus:		${OBJS} ${B_OBJS}
			ar rc $(NAME) ${OBJS} ${B_OBJS}
			ranlib $(NAME)

.PHONY:		all clean fclean re