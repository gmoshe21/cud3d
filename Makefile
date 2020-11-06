SRCS            =   srcs/main.c\
                    srcs/key.c\
                    srcs/pars_sprites.c\
                    srcs/check.c\
                    srcs/tracking_movement.c\
                    srcs/pars.c\
                    srcs/raycast.c\
                    srcs/raycasting.c\
                    srcs/sprites.c\
                    srcs/bmp.c\
                    srcs/filling.c\
                    srcs/filling2.c\
                    srcs/free.c\

OBJS            = $(SRCS:.c=.o)

CC              = clang

RM              = rm -f

CFLAGS          = -O3 -g -Wall -Wextra -Werror -Iinc/ -Imlx/ -Ilibft/inc/

LIBS            = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm -Llibft -lft

MLX             = libmlx.dylib

LIBFT           = ./libft/libft.a

NAME            = cub3D

all:            $(NAME)

$(NAME):        $(LIBFT) $(OBJS) $(MLX) $(LIBFT)
					clang ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}
					@cp mlx/$(MLX) .

$(LIBFT):       $(MLX)
				@$(MAKE) -C libft

$(MLX):
				@$(MAKE) -C mlx

clean:
				$(RM) $(OBJS)

fclean:         clean
				$(RM) $(NAME) $(MLX) $(LIBFT) ./mlx/$(MLX)

re:             fclean $(NAME)

.PHONY:         all clean fclean re libft