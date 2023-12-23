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
