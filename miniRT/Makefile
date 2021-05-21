NAME	= miniRT

HEAD	= includes

SRCDIR	= srcs/

LIB		= lib/

FILES	= 	camera.c										\
			color.c											\
			cylindre_intersection.c							\
			error.c											\
			light.c											\
			minirt.c										\
			multithreading.c								\
			other_intersection.c							\
			parsing_info.c									\
			parsing_info_two.c								\
			parsing_bonus.c									\
			parsing_utils.c									\
			parsing_utils_two.c								\
			parsing.c										\
			plane_intersection.c							\
			rainbow.c										\
			simple_pixel.c									\
			sphere_intersection.c							\
			supersimple.c									\
			texture.c										\
			utils.c											\
			utils_two.c										\
			save_bmp.c										\
			../$(LIB)ft_printf/print_x.c					\
			../$(LIB)ft_printf/print_u.c					\
			../$(LIB)ft_printf/print_s.c					\
			../$(LIB)ft_printf/print_prc.c					\
			../$(LIB)ft_printf/print_p.c					\
			../$(LIB)ft_printf/print_other.c				\
			../$(LIB)ft_printf/print_di.c					\
			../$(LIB)ft_printf/print_di_addons.c			\
			../$(LIB)ft_printf/print_c.c					\
			../$(LIB)ft_printf/parse_all.c					\
			../$(LIB)ft_printf/ft_printf.c					\
			../$(LIB)ft_printf/utils/ft_lltoa_base_x.c		\
			../$(LIB)ft_printf/utils/ft_putnbr_base.c		\
			../$(LIB)ft_printf/utils/get_n_size.c			\
			../$(LIB)ft_printf/utils/is_set.c				\

SRCS	= $(addprefix $(SRCDIR), $(FILES))

OBJS	= ${SRCS:.c=.o}

CC		= gcc -g

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -I $(HEAD) -D NUM_THREADS=$(NUM_THREADS)

FLAGS = -L $(LIB)libft -lft -L $(LIB)libvector -lvct

MACOS_MACRO = -D MACOS

LINUX_MACRO = -D LINUX

MACOS_FLAGS	= -L $(LIB)minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit 

LINUX_FLAGS = -L $(LIB)minilibx-linux -lmlx -lm -lX11 -lXext -lpthread

UNAME := $(shell uname)

ifeq ($(UNAME),Darwin)
	NUM_THREADS = $(shell sysctl -n hw.ncpu)
	CFLAGS += $(MACOS_MACRO)
	FLAGS += $(MACOS_FLAGS)
endif
ifeq ($(UNAME),Linux)
	NUM_THREADS = $(shell nproc --all)
	CFLAGS += $(LINUX_MACRO)
	FLAGS += $(LINUX_FLAGS)
endif

${NAME}:	${OBJS}
			make -C $(LIB)libft
			make -C $(LIB)libvector
			${CC} ${CFLAGS} $(OBJS) $(FLAGS) -o ${NAME}

all:		${NAME}

clean:
			make clean -C $(LIB)libft
			make clean -C $(LIB)libvector
			${RM} ${OBJS}

fclean:		clean
			make fclean -C $(LIB)libft
			make fclean -C $(LIB)libvector
			${RM} ${NAME}

re:			fclean all

PHONY:		all clean fclean re
