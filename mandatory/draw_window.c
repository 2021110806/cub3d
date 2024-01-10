/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:05:34 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/10 15:56:21 by minjeon2         ###   ########.fr       */
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
			{
				data->buf[y][x] = rgb_convert_int(data -> args.ceiling_color);
			}
			else
			{
				data->buf[y][x] = rgb_convert_int(data -> args.floor_color);
			}
			x++;
		}
		y++;
	}
}

void	draw_map_one_space(int draw_start_y, int draw_start_x, \
t_data *data, t_rgb_color color)
{
	int	draw_end_y;
	int	draw_end_x;
	int	draw_current_x;
	int	draw_current_y;

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
