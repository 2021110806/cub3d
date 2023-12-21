/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:25:10 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/21 19:21:47 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	set_texture(t_data *data, char *direction, int index)
{
	int	i;
	int	j;
	t_image_info img;

	i = 0;
	img.image = mlx_xpm_file_to_image(data -> mlx, direction, &img.width, &img.height);
	img.texture = (int *) mlx_get_data_addr(img.image, &img.bit_per_pixel, &img.size, &img.endian);
	while (i < img.height)
	{
		j = 0;
		while (j < img.width)
		{
			data -> texture[index][img.width * i + j] = img.texture[img.width * i + j];
			j++;
		}
		i++;
	}
	mlx_destroy_image(data -> mlx, img.image);
}

void	set_player(t_data *data)
{
	data -> player_position_x = 22.0;
	data -> player_position_y = 11.5;
	data -> player_view_direction_x = -1.0;
	data -> player_view_direction_y = 0.0;
	data -> camera_plane_x = 0.0;
	data -> camera_plane_y = 0.66;
	data -> move_speed = 0.15;
	data -> rotate_speed = 0.10;
}

void set_curr_measurement_vector(t_int_coordinate *map, t_data *data, t_int_coordinate *step, t_vectors *vectors)
{
	if (vectors -> ray_vector.x < 0)
	{
		step -> x = -1;
		vectors -> curr_measurement_vector.x  = \
		(data -> player_position_x - map -> x) * vectors -> delta_vector.x;
	}
	else
	{
		step -> x = 1;
		vectors -> curr_measurement_vector.x = \
		(map -> x + 1.0 - data -> player_position_x) * vectors -> delta_vector.x;
	}
	if (vectors -> ray_vector.y < 0)
	{
		step -> y = -1;
		vectors -> curr_measurement_vector.y  = \
		(data -> player_position_y - map -> y) * vectors -> delta_vector.y;
	}
	else
	{
		step -> y = 1;
		vectors -> curr_measurement_vector.y = \
		(map -> y + 1.0 - data -> player_position_y) * vectors -> delta_vector.y;
	}
}

void	move_ray\
(t_vectors *vectors, t_int_coordinate *map, t_data *data, t_int_coordinate step)
{
	int	hit;
	int	last_hit_pos;

	hit = 0;
	while (!hit)
	{
		if (vectors -> curr_measurement_vector.x < vectors -> curr_measurement_vector.y)
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
		if (worldMap[map -> x][map -> y] > 0)
			hit = 1;
		data -> last_hit_pos = last_hit_pos;
	}
}

void	set_vector(t_data *data, t_vectors *vectors, t_int_coordinate *map)
{
	vectors -> ray_vector.x = \
	data -> player_view_direction_x + data -> camera_plane_x * data -> curr_ratio;
	vectors -> ray_vector.y = \
	data -> player_view_direction_y + data -> camera_plane_y * data -> curr_ratio;
	vectors -> delta_vector.x = fabs(1 / vectors -> ray_vector.x);
	vectors -> delta_vector.y = fabs(1 / vectors -> ray_vector.y);
	map -> x = (int) data -> player_position_x;
	map -> y = (int) data -> player_position_y;
}

int	set_wall(t_data *data)
{
	int					x;
	double				vertical_distance;
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
		vertical_distance = \
		calculate_distance_from_camera_to_wall(map, data, vectors, step);
		draw_image(vertical_distance, &map, data, &vectors, x);
		x++;
	}
	return (0);
}

int play(t_data *data)
{
	draw_floor_and_ceiling(data);
	set_wall(data);
	draw(data);
	return (0);
}

void set_textures(t_data *data)
{
	set_texture(data, EAST_PATH, 0);
	set_texture(data, EAST_PATH, EAST);
	set_texture(data, WEST_PATH, WEST);
	set_texture(data, SOUTH_PATH, SOUTH);
	set_texture(data, NORTH_PATH, NORTH);
	set_texture(data, WEST_PATH, FLOOR);
	set_texture(data, SOUTH_PATH, CEILING);
	set_texture(data, NORTH_PATH, 7);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	(void) argc;
	(void) argv;
	data.mlx = mlx_init();
	set_player(&data);
	init_buf(&data);
	data.texture = ft_int_pointer_malloc(8);
	while (i < 8)
		data .texture[i++] = ft_int_malloc(TEXTURE_HEGIHT * TEXTURE_WIDTH);
	set_textures(&data);
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, GAME_NAME);
	data.img.image = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.img.texture = (int *) mlx_get_data_addr(data.img.image, &data.img.bit_per_pixel, &data.img.size, &data.img.endian);
	mlx_loop_hook(data.mlx, play, &data);
	mlx_hook(data.win, KEY_PRESS_EVENT, 0, &key_press, &data);
	mlx_loop(data.mlx);
}

