# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 16:31:47 by minkyole          #+#    #+#              #
#    Updated: 2023/12/21 20:41:41 by minjeon2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = mlx
FRAMEWORK = -framework Appkit -framework OpenGL
NAME = cub3d
SRCS = main.c init_data.c utils.c draw_window.c draw_window_utils.c key_press.c dda.c init_vector.c draw_window_setting.c set_direction.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -l$(MLX_DIR) -L$(MLX_DIR) $(FRAMEWORK) $^ -o $@

clean:
	rm -f $(OBJS)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $^ -o $@

all: $(NAME)
