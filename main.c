/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:25:10 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/16 21:29:27 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture(t_data *data,char *direction)
{
	int	i;
	int	j;
	t_image_info *img;

	i = 0;
	j = 0;
	img = malloc (sizeof (t_image_info));
	if (!img)
		exit(1);
	img -> image = mlx_xpm_file_to_image(data -> mlx, direction, img ->width, img -> height);
	img -> texture = (int *) mlx_get_data_addr(img -> image, img -> bit_per_pixel, img -> size, img -> endian);
	while (i < img -> height)
	{
		while (j < img -> width)
		{
			data -> texture[img -> width * i + j] = \
			img -> texture[img -> width * i + j];
			j++;
		}
	}
	mlx_destroy_image(data -> mlx, img -> image);
	free(img);
}

int	set_player(t_data *data, char **argv)
{
	data -> player_position_X = 22.0;
	data -> player_position_Y = 11.5;
	data -> player_view_X = 0.0;
	data -> player_position_Y = 0.66;
	data -> camera_X = 0.0;
	data -> camera_Y = 0.66;
}

void color_buf_with_texture(t_data *data, int x, int y)
{
	int color;

	color = data -> texture[FLOOR][TEX_HEGIHT * y + x]; // 수식 소신껏 바꿨는데 맞는지 몰루
	data -> buf[y][x] = color;
	
	color = data -> texture[CEILING][TEX_HEGIHT * y + x]; //바꿈
	data -> buf[WIN_HEIGHT - y - 1][x] = color; 
}
int set_floor_and_ceiling(t_data *data)
{
	float 	left_side_x;
	float	left_side_y;
	float	right_side_x;
	float	right_side_y;
	float	middle_to_pos_ratio;
	int y;
	int	x;

	y = 0;
	x = 0;
	while (y < WIN_HEIGHT)
	{
		left_side_x = data -> player_view_X - data -> camera_X;
		left_side_y = data -> player_view_Y - data -> camera_Y;
		right_side_x = data -> player_view_X + data -> camera_X;
		right_side_y = data -> player_view_Y + data -> camera_Y;
		middle_to_pos_ratio = (0.5 / WIN_HEIGHT) / (y - WIN_HEIGHT * 0.5); //전체 화면 중앙점 나누기 떨어진 거리 - 수식 바꿈
		// 화면 크기 10, y = 2 -> 5 / (2 - 5) -> 5 / -3
		
		float step_x = middle_to_pos_ratio * (right_side_x - left_side_x) / WIN_WIDTH; //실제 화면상 길이로 변환?
		float step_y = middle_to_pos_ratio * (right_side_x - left_side_x) / WIN_WIDTH;
		
		float draw_x = data -> player_position_X + middle_to_pos_ratio * left_side_x;
		float draw_y = data -> player_position_Y + middle_to_pos_ratio * left_side_y;

		
		x = 0;
		while (x < WIN_WIDTH)
		{
			int texture_start_x = (int) (TEX_WIDTH * (draw_x - (int) draw_x)) & (TEX_WIDTH - 1);
			int	texture_start_y = (int) (TEX_HEGIHT * (draw_y - (int) draw_y)) & (TEX_WIDTH - 1);
			
			draw_x += step_x;
			draw_y += step_y;
			
			color_buf_with_texture(data, x, y);
		}
		y++;
	}
}
int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	i = 0;
	init_data(data);	
	set_player(data, argv);
	init_buf(data);
	data -> texture = ft_int_pointer_malloc(4);
	while (i < 4)
		data -> texture[i++] = ft_int_malloc(TEX_HEGIHT * TEX_WIDTH);
	set_texture(data, WEST_PATH);
	set_texture(data, EAST_PATH);
	set_texture(data, NORTH_PATH);
	set_texture(data, SOUTH_PATH);
	
	data -> win = mlx_new_window(data -> mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	data -> img -> image = mlx_new_image(data -> mlx, WIN_WIDTH, WIN_HEIGHT);
	data -> img ->texture = (int *) mlx_get_data_addr(data -> img -> image, data -> img -> bit_per_pixel, data -> img -> size, data -> img -> endian);
	
	mlx_loop_hook(data -> mlx, )
}

