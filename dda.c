/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:30:18 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/28 17:26:27 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calculate_distance_from_camera_to_wall(t_int_coordinate map, \
t_data *data, t_vectors vectors, t_int_coordinate step)
{
	if (data -> last_hit_pos == X)
		return ((map.x - data -> player_position_x + (1 - step.x) / 2) \
				/ vectors.ray_vector.x);
	return ((map.y - data -> player_position_y + (1 - step.y) / 2) \
			/ vectors.ray_vector.y);
}

void	move_ray(t_vectors *vectors, \
t_int_coordinate *map, t_data *data, t_int_coordinate step)
{
	int	hit;
	int	last_hit_pos;

	hit = 0;
	while (!hit)
	{
		if (vectors -> curr_measurement_vector.x \
		< vectors -> curr_measurement_vector.y)
		{
			vectors -> curr_measurement_vector.x += vectors -> delta_vector.x;
			map -> x += step.x;
			last_hit_pos = X;
		}
		else
		{
			vectors -> curr_measurement_vector.y += vectors -> delta_vector.y;
			map -> y += step.y;
			last_hit_pos = Y;
		}
		if (data -> args.map.map[map -> y][map -> x] == '1' || \
		data -> args.map.map[map -> y][map -> x] == '2' || \
		data -> args.map.map[map -> y][map -> x] == '3')
			hit = 1;
		data -> last_hit_pos = last_hit_pos;
	}
}
