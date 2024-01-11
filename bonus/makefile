# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 16:31:47 by minkyole          #+#    #+#              #
#    Updated: 2024/01/11 21:40:05 by minjeon2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = ../mlx
MLX = ../mlx/libmlx.a
FRAMEWORK = -framework Appkit -framework OpenGL
LIBFT = ../libft/libft.a
LIBFT_DIR = ../libft
NAME = cub3D
SRCS = color_valid_utils_bonus.c set_texture_path_bonus.c exception_bonus.c \
parser_bonus.c parser_utils_bonus.c main_bonus.c init_data_bonus.c \
utils_bonus.c draw_window_bonus.c draw_window_utils_bonus.c \
key_press_bonus.c dda_bonus.c init_vector_bonus.c get_next_line_bonus.c \
get_next_line_utils_bonus.c draw_window_setting_bonus.c \
set_direction_bonus.c draw_window_setting_bonus.c color_bonus.c \
mouse_bonus.c minimap_utils_bonus.c set_texture_path_bearing_bonus.c \
map_line_validator_bonus.c map_structure_validator_bonus.c utils2_bonus.c \
parser_valid_bonus.c parser_map_bonus.c parser_sprite_bonus.c \
sprite_print_setting_bonus.c utils3_bonus.c sprite_setting_bonus.c \
sprite_sort_bonus.c move_command_bonus.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -lmlx -L$(MLX_DIR) \
	$(FRAMEWORK) $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $^ -o $@
	
$(MLX):
	make -C $(MLX_DIR)

all: $(NAME)
