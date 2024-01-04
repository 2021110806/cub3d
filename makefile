# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 16:31:47 by minkyole          #+#    #+#              #
#    Updated: 2024/01/04 17:30:27 by minjeon2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_DIR = mlx
FRAMEWORK = -framework Appkit -framework OpenGL
LIBFT = ./libft/libft.a
LIBFT_DIR = libft
NAME = cub3d
SRCS = set_texture_path.c exception.c parser.c parser_utils.c main.c init_data.c utils.c draw_window.c draw_window_utils.c key_press.c dda.c init_vector.c get_next_line.c get_next_line_utils.c draw_window_setting.c set_direction.c draw_window_setting.c color.c mouse.c minimap_utils.c set_texture_path_bearing.c map_line_validator.c map_structure_validator.c utils2.c parser_valid.c parser_map.c parser_sprite.c sprite_print_setting.c utils3.c sprite_setting.c sprite_sort.c 

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
