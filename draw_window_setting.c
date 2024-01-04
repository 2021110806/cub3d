/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window_setting.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:27:17 by minkyole          #+#    #+#             */
/*   Updated: 2023/12/29 17:53:06 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_draw_texture_number(t_drawing_factors *drawing_factors, \
t_data *data, t_int_coordinate step, t_int_coordinate map)
{
	if (data -> args.map.map[map.y][map.x] == MINIMAP_CLOSE_DOOR)
		drawing_factors -> texture_number = CLOSE_DOOR;
	else if (data -> args.map.map[map.y][map.x] == MINIMAP_OPEN_DOOR)
		drawing_factors -> texture_number = OPENED_DOOR;
	else if (data -> last_hit_pos == X && step.x == 1)
		drawing_factors -> texture_number = EAST;
	else if (data -> last_hit_pos == X && step.x == -1)
		drawing_factors -> texture_number = WEST;
	else if (data -> last_hit_pos == Y && step.y == 1)
		drawing_factors -> texture_number = SOUTH;
	else if (data -> last_hit_pos == Y && step.y == -1)
		drawing_factors -> texture_number = NORTH;
	//printf(">>> : %d\n", drawing_factors -> texture_number);
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
		//printf("0.1\n");
		data -> curr_ratio = -(2 * x / (double) WIN_WIDTH - 1);
		set_vector(data, &vectors, &map);
		//printf("0.2\n");
		set_curr_measurement_vector(&map, data, &step, &vectors);
		//printf("0.3\n");
		move_ray(&vectors, &map, data, step);
		//printf("0.4\n");
		drawing_factors.vertical_distance = \
		calculate_distance_from_camera_to_wall(map, data, vectors, step);
		//printf("0.5\n");
		drawing_factors.x = x;
		calculate_draw_texture_number(&drawing_factors, data, step, map);
		//printf("0.6\n");
		//printf("map_x %d map_y %d\n", map.x, map.y);
		draw_image(&drawing_factors, data, &vectors);
		//printf("0.7\n");
		x++;
		data->sprite_buffer[x] = drawing_factors.vertical_distance;
	}
	return (0);
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

	//printf("texture_number start1 %d\n", drawing_factors->texture_number);
	//printf("0.61\n");
	set_drawing_factors(drawing_factors, data, vectors);
	//printf("texture_number start2 %d\n", drawing_factors->texture_number);
	//printf("0.62\n");
	texture_x = \
	calculate_texture_spot(data, vectors, drawing_factors -> wall_crash_spot);
	//printf("texture_number start3 %d\n", drawing_factors->texture_number);
	//printf("0.63\n");
	y = drawing_factors -> draw_start;
	while (y < drawing_factors -> draw_end)
	{
		//printf("texture_number start4 %d\n", drawing_factors->texture_number);
		//printf("0.631\n");
		texture_y = \
		(int) drawing_factors -> curr_drawing_spot & (TEXTURE_HEGIHT - 1);
		//printf("texture_number start5 %d\n", drawing_factors->texture_number);
		//printf("0.632\n");
		drawing_factors -> curr_drawing_spot += drawing_factors -> delta;
		// printf("texture_number start6 %d\n", drawing_factors->texture_number);
		// printf("texutre second %d\n", TEXTURE_HEGIHT * texture_y + texture_x);
		// printf("%d\n", data->texture[drawing_factors->texture_number][1]);
		// printf("0.633\n");
		// printf(" y %d", texture_y);
		// printf(" x %d\n", texture_x);
		// printf("texture_number %d", drawing_factors->texture_number);
		// printf(" color %d", data->texture[drawing_factors->texture_number][TEXTURE_HEGIHT * texture_y + texture_x]);
		//printf("y %d x %d\n", drawing_factors->texture_number, TEXTURE_HEGIHT * texture_y + texture_x);
		color = data -> texture[drawing_factors->texture_number] \
		[TEXTURE_HEGIHT * texture_y + texture_x];
		//printf("0.634\n");
		if (data->last_hit_pos == Y)
			color = (color >> 1) & 8355711;
		//printf("0.635\n");
		data -> buf[y][drawing_factors -> x] = color;
		//printf("0.636\n");
		y++;
	}
	//printf("0.64\n");
}
