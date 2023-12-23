/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:24:14 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/21 20:40:47 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_textures(t_data *data)
{
	set_texture(data, EAST_PATH, EAST);
	set_texture(data, WEST_PATH, WEST);
	set_texture(data, SOUTH_PATH, SOUTH);
	set_texture(data, NORTH_PATH, NORTH);
}

double	calculate_wall_crash_spot(t_data *data, \
double vertical_distance, t_vectors *vectors)
{
	double	wall_crash_spot;

	if (data -> last_hit_pos == X)
		wall_crash_spot = \
		data->player_position_y + vertical_distance * vectors->ray_vector.y;
	else
		wall_crash_spot = \
		data->player_position_x + vertical_distance * vectors->ray_vector.x;
	wall_crash_spot -= floor(wall_crash_spot);
	return (wall_crash_spot);
}

int	calculate_texture_spot(t_data *data, \
t_vectors *vectors, double wall_crash_spot)
{
	int	texture_x;

	texture_x = (long)(wall_crash_spot * (double)TEXTURE_WIDTH);
	if ((data -> last_hit_pos == X && vectors->ray_vector.x > 0) || \
	(data -> last_hit_pos == Y && vectors->ray_vector.y < 0))
		return (TEXTURE_WIDTH - texture_x - 1);
	return (texture_x);
}

int	calculate_draw_start(int line_height)
{
	int	draw_start;

	draw_start = -line_height / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		return (0);
	return (draw_start);
}

int	calculate_draw_end(int line_height)
{
	int	draw_end;

	draw_end = line_height / 2 + WIN_HEIGHT / 2;
	if (draw_end >= WIN_HEIGHT)
		return (WIN_HEIGHT);
	return (draw_end);
}