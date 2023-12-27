/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:05:34 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/21 20:40:35 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_and_ceiling(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				data->buf[y][x] = 123123 & 8355711;
			else
				data->buf[y][x] = 10000001;
			x++;
		}
		y++;
	}
}

#include <stdio.h>

void	draw_map_one_space(int draw_start_y, int draw_start_x, t_data *data, t_rgb_color color)
{
	int	draw_end_y;
	int	draw_end_x;
	int	draw_current_x;
	int draw_current_y;

	draw_current_y = draw_start_y;
	draw_end_y = draw_start_y + MAP_ONE_SPACE_SIZE;
	draw_end_x = draw_start_x - MAP_ONE_SPACE_SIZE;
	while (draw_current_y < draw_end_y)
	{
		draw_current_x = draw_start_x;
		while (draw_current_x > draw_end_x)
		{
			data->buf[draw_current_y][draw_current_x] = rgb_convert_int(color);
			draw_current_x--;
		}
		draw_current_y++;
	}
}

void	draw_minimap(t_data *data)
{
	t_rgb_color empty_color;
	t_rgb_color player_color;
	t_rgb_color wall_color;
	t_rgb_color null_color;
	int y;
	int x;
	int current_location;

	y = 0;
	set_rgb_color(&null_color, 189, 189, 189);
	set_rgb_color(&player_color, 255, 0, 221);
	set_rgb_color(&empty_color, 183, 240, 177);
	set_rgb_color(&wall_color, 153, 112, 0);

	while (y < 11)
	{
		x = 0;
		while (x < 11)
		{
			current_location = check_minimap_current_location(y, x, data);
			if (current_location == MINIMAP_NULL)
				draw_map_one_space(y * MAP_ONE_SPACE_SIZE, WIN_WIDTH - x * MAP_ONE_SPACE_SIZE, data, null_color);
			else if (current_location == MINIMAP_WALL)
				draw_map_one_space(y * MAP_ONE_SPACE_SIZE, WIN_WIDTH - x * MAP_ONE_SPACE_SIZE, data, wall_color);
			else if (current_location == MINIMAP_EMPTY)
				draw_map_one_space(y * MAP_ONE_SPACE_SIZE, WIN_WIDTH - x * MAP_ONE_SPACE_SIZE, data, empty_color);
			else if (current_location == MINIMAP_PLAYER)
				draw_map_one_space(y * MAP_ONE_SPACE_SIZE, WIN_WIDTH - x * MAP_ONE_SPACE_SIZE, data, player_color);
			x++;
		}
		y++;
	}
}

void	draw_buf(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			data->img.texture[y * WIN_WIDTH + x] = data->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
}
