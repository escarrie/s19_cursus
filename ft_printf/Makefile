# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escarrie <escarrie@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 16:01:36 by escarrie          #+#    #+#              #
#    Updated: 2020/09/28 10:42:36 by escarrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS		= 	ft_printf.c						\
				parse_all.c						\
				print_di.c						\
				print_di_addons.c				\
				print_other.c					\
				print_c.c						\
				print_p.c						\
				print_s.c						\
				print_u.c						\
				print_x.c						\
				print_prc.c						\
				utils/ft_putnbr_base.c			\
				utils/get_n_size.c				\
				utils/is_set.c					\
				utils/ft_lltoa_base_x.c			\


OBJS		= $(SRCS:.c=.o)
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME) $(bonus)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all

bonus : all

.PHONY: all clean fclean re bonus .c.o