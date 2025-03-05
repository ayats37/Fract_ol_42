SRCS = ./Mandatory/window.c ./Mandatory/main.c ./Mandatory/mandelbrot.c ./Mandatory/hooks.c ./Mandatory/julia.c ./Mandatory/utils.c
SRCS_BONUS = ./Bonus/window_bonus.c ./Bonus/main_bonus.c ./Bonus/mandelbrot_bonus.c ./Bonus/hooks_bonus.c ./Bonus/julia_bonus.c ./Bonus/utils_bonus.c ./Bonus/tricorn_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = fractol

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MLX_FLAGS) -o $(NAME)

bonus: $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
