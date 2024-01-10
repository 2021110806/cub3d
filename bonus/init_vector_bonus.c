/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vector_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:34:56 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/10 16:16:34 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_x_vector(t_int_coordinate *map, t_data \
*data, t_int_coordinate *step, t_vectors *vectors)
{
	if (vectors -> ray_vector.x < 0)
	{
		step -> x = -1;
		vectors -> curr_measurement_vector.x = \
		(data -> player_position_x - map -> x) * vectors -> delta_vector.x;
	}
	else
	{
		step -> x = 1;
		vectors -> curr_measurement_vector.x = \
		(map -> x + 1.0 - data -> player_position_x) \
		* vectors -> delta_vector.x;
	}
}

void	set_y_vector(t_int_coordinate *map, t_data \
*data, t_int_coordinate *step, t_vectors *vectors)
{
	if (vectors -> ray_vector.y < 0)
	{
		step -> y = -1;
		vectors -> curr_measurement_vector.y = \
		(data -> player_position_y - map -> y) * vectors -> delta_vector.y;
	}
	else
	{
		step -> y = 1;
		vectors -> curr_measurement_vector.y = \
		(map -> y + 1.0 - data -> player_position_y) \
		* vectors -> delta_vector.y;
	}
}

void	set_curr_measurement_vector(t_int_coordinate *map, t_data \
*data, t_int_coordinate *step, t_vectors *vectors)
{
	set_x_vector(map, data, step, vectors);
	set_y_vector(map, data, step, vectors);
}

void	set_vector(t_data *data, t_vectors *vectors, t_int_coordinate *map)
{
	vectors -> ray_vector.x = \
	data -> player_view_direction_x + \
	data -> camera_plane_x * data -> curr_ratio;
	vectors -> ray_vector.y = \
	data -> player_view_direction_y + \
	data -> camera_plane_y * data -> curr_ratio;
	vectors -> delta_vector.x = fabs(1 / vectors -> ray_vector.x);
	vectors -> delta_vector.y = fabs(1 / vectors -> ray_vector.y);
	map -> x = (int) data -> player_position_x;
	map -> y = (int) data -> player_position_y;
}
