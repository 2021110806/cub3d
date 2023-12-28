# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 16:31:47 by minkyole          #+#    #+#              #
#    Updated: 2023/12/28 19:35:58 by minjeon2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = mlx
FRAMEWORK = -framework Appkit -framework OpenGL
LIBFT = ./libft/libft.a
LIBFT_DIR = libft
NAME = cub3d
SRCS = parser.c parser_utils.c main.c init_data.c utils.c draw_window.c draw_window_utils.c key_press.c dda.c init_vector.c get_next_line.c get_next_line_utils.c draw_window_setting.c set_direction.c draw_window_setting.c color.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -l$(MLX_DIR) -L$(MLX_DIR) $(FRAMEWORK) $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) fclean

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $^ -o $@

all: $(NAME)
