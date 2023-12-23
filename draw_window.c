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

void	calculate_draw_texture_number(t_drawing_factors *drawing_factors, \
t_data *data, t_int_coordinate step)
{
	if (data -> last_hit_pos == X && step.x == 1)
		drawing_factors -> texture_number = WEST;
	else if (data -> last_hit_pos == X && step.x == -1)
		drawing_factors -> texture_number = EAST;
	else if (data -> last_hit_pos == Y && step.y == 1)
		drawing_factors -> texture_number = SOUTH;
	else if (data -> last_hit_pos == Y && step.y == -1)
		drawing_factors -> texture_number = NORTH;
}

int	draw_wall(t_data *data)
{
	int					x;
	t_drawing_factors	drawing_factors;
	t_vectors			vectors;
	t_int_coordinate	map;
	t_int_coordinate	step;

	x = 0;
	while (x < WIN_WIDTH)
	{
		data -> curr_ratio = 2 * x / (double) WIN_WIDTH - 1;
		set_vector(data, &vectors, &map);
		set_curr_measurement_vector(&map, data, &step, &vectors);
		move_ray(&vectors, &map, data, step);
		drawing_factors.vertical_distance = \
		calculate_distance_from_camera_to_wall(map, data, vectors, step);
		drawing_factors.x = x;
		calculate_draw_texture_number(&drawing_factors, data, step);
		draw_image(&drawing_factors, data, &vectors);
		x++;
	}
	return (0);
}

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

void	set_drawing_factors(t_drawing_factors *drawing_factors, \
t_data *data, t_vectors *vectors)
{
	drawing_factors -> line_height = \
	WIN_HEIGHT / drawing_factors -> vertical_distance;
	drawing_factors -> draw_start = \
	calculate_draw_start(drawing_factors -> line_height);
	drawing_factors -> draw_end = \
	calculate_draw_end(drawing_factors -> line_height);
	drawing_factors -> delta = \
	(1.0 * TEXTURE_HEGIHT / drawing_factors -> line_height);
	drawing_factors -> curr_drawing_spot = (drawing_factors -> \
	draw_start - WIN_HEIGHT / 2 + drawing_factors -> line_height / 2) \
	* drawing_factors -> delta;
	drawing_factors -> wall_crash_spot = \
	calculate_wall_crash_spot(data, drawing_factors -> \
	vertical_distance, vectors);
}

void	draw_image(t_drawing_factors *drawing_factors, \
t_data *data, t_vectors *vectors)
{
	int	texture_x;
	int	texture_y;
	int	color;
	int	y;

	set_drawing_factors(drawing_factors, data, vectors);
	texture_x = \
	calculate_texture_spot(data, vectors, drawing_factors -> wall_crash_spot);
	y = drawing_factors -> draw_start;
	while (y < drawing_factors -> draw_end)
	{
		texture_y = \
		(int) drawing_factors -> curr_drawing_spot & (TEXTURE_HEGIHT - 1);
		drawing_factors -> curr_drawing_spot += drawing_factors -> delta;
		color = data -> texture[drawing_factors->texture_number] \
		[TEXTURE_HEGIHT * texture_y + texture_x];
		if (data->last_hit_pos == Y)
			color = (color >> 1) & 8355711;
		data -> buf[y][drawing_factors -> x] = color;
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
