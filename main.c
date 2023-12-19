/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:25:10 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/18 20:21:31 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	worldMap[24][24] =
						{
							{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
							{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
							{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
							{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
							{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
							{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
							{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
							{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
							{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
							{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
							{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
							{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
							{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
							{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
							{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
							{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
							{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
							{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
							{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
						};

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
			// printf("texture %d\n", data -> texture[index][img.width * i + j]);
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
	data -> rotate_speed = 0.15;
}

void set_curr_measurement_vector(t_int_coordinate *map, t_data *data, t_int_coordinate *step, t_vectors *vectors)
{
	if (vectors -> ray_vector.x < 0)
	{
		step -> x = -1;
		vectors -> curr_measurement_vector.x  = (data -> player_position_x - map -> x) * vectors -> delta_vector.x;
	}
	else
	{
		step -> x = 1;
		vectors -> curr_measurement_vector.x = (map -> x + 1.0 - data -> player_position_x) * vectors -> delta_vector.x;
	}
	if (vectors -> ray_vector.y < 0)
	{
		step -> y = -1;
		vectors -> curr_measurement_vector.y  = (data -> player_position_y - map -> y) * vectors -> delta_vector.y;
	}
	else
	{
		step -> y = 1;
		vectors -> curr_measurement_vector.y = (map -> y + 1.0 - data -> player_position_y) * vectors -> delta_vector.y;
	}
}

void move_ray(t_vectors *vectors, t_int_coordinate *map, t_data *data, t_int_coordinate step)
{
	int	hit;
	int last_hit_pos;

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
			vectors -> curr_measurement_vector.y = vectors -> delta_vector.y;
			map -> y += step.y;
			last_hit_pos = Y;
		}
		if (worldMap[map -> x][map -> y] > 0)
			hit = 1;
		data -> last_hit_pos = last_hit_pos;
	}
}

double calculate_vertical_distance_from_camera_to_wall(t_int_coordinate map, t_data *data, t_vectors vectors, t_int_coordinate step)
{
	if (data -> last_hit_pos == X)
	{
		printf("step_x %d ray_vector_x %f\n", step.x, vectors.ray_vector.x);
		return (map.x - data -> player_position_x + (1 - step.x) / 2) / vectors.ray_vector.x;
	}
	printf("step_y %d ray_vector_y %f\n", step.y, vectors.ray_vector.y);
	return (map.y - data -> player_position_y + (1 - step.y) / 2) / vectors.ray_vector.y;
}

int calculate_draw_start(int line_height)
{
	int draw_start;

	draw_start = -line_height  / 2 + WIN_HEIGHT / 2;
	if (draw_start < 0)
		return (0);
	return (draw_start);
}

int calculate_draw_end(int line_height)
{
	int draw_end;

	draw_end = line_height  / 2 + WIN_HEIGHT / 2;
	if (draw_end >= WIN_HEIGHT)
		return (WIN_HEIGHT - 1);
	return (draw_end);
}

double calculate_wall_crash_spot(t_data *data, double vertical_distance, t_vectors *vectors)
{
	double wall_crash_spot;
	
	if (data -> last_hit_pos == X)
		wall_crash_spot = (data -> player_position_y + vertical_distance * vectors->ray_vector.y);
	else 
		wall_crash_spot = (data -> player_position_x + vertical_distance * vectors->ray_vector.x);
	wall_crash_spot = floor(wall_crash_spot);
	return (wall_crash_spot);
}

int calculate_texture_spot(t_data *data, t_vectors *vectors, double wall_crash_spot)
{
	int texture_print_spot;
	
	texture_print_spot = (int)(wall_crash_spot * (double)TEXTURE_WIDTH);
	if ((data -> last_hit_pos == X && vectors->ray_vector.x > 0) || (data -> last_hit_pos == Y && vectors->ray_vector.y < 0))
		return (TEXTURE_WIDTH - texture_print_spot - 1);
	return (texture_print_spot);
	
}

void draw_image(double vertical_distance, t_int_coordinate *map, t_data *data, t_vectors *vectors, int x)
{
	int draw_start;
	int draw_end;
	int	line_height;
	int	texture_number;
	double wall_crash_spot;
	int	texture_x;
	double curr_drawing_spot;
	int	y;
	double delta;

	line_height = WIN_HEIGHT / vertical_distance;
	// printf("line_height %d vertical_distance %f\n", line_height, vertical_distance);
	draw_start = calculate_draw_start(line_height);
	draw_end = calculate_draw_end(line_height);
	// printf("draw_start %d draw_end %d\n", draw_start, draw_end);
	texture_number = worldMap[map -> y][map -> x];
	delta = (1.0 * TEXTURE_HEGIHT / line_height);
	curr_drawing_spot = (draw_start - WIN_HEIGHT / 2 + line_height / 2) * delta;
	wall_crash_spot = calculate_wall_crash_spot(data, vertical_distance, vectors);
	texture_x = calculate_texture_spot(data, vectors, wall_crash_spot);

	y = draw_start;
	while (y < draw_end)
	{
		int texture_y = (int) curr_drawing_spot & (TEXTURE_HEGIHT - 1);
		curr_drawing_spot += delta;
		int color = data -> texture[texture_number][TEXTURE_HEGIHT * texture_y + texture_x];
		// printf ("color %d texture_number %d texture y %d texture x %d drawend %d y %d drawstart %d\n", color, texture_number, texture_y, texture_x, draw_end, y, draw_start);
		if (data->last_hit_pos == Y)
			color = (color >> 1) & 8355711;
		data -> buf[y][x] = color;
		y++;
	}
	
}

int set_wall(t_data *data)
{
	int 			x;
	double			vertical_distance;
	t_vectors		vectors;
	t_int_coordinate map;
	t_int_coordinate step;

	x = 0;
	while (x < WIN_WIDTH)
	{
		double curr_ratio = 2 * x / (double) WIN_WIDTH - 1;
		vectors.ray_vector.x = data -> player_view_direction_x + data -> camera_plane_x * curr_ratio;
		vectors.ray_vector.y = data -> player_view_direction_y + data -> camera_plane_y * curr_ratio;
		printf("curr_ratio %f ray_vector_X %f ray_vector_Y %f player_view_direcion %f camera_plane_y %f\n", curr_ratio, vectors.ray_vector.x, vectors.ray_vector.y, data->player_view_direction_y, data->camera_plane_y);
		printf("cal ray_Vecotr Y1 %f\n", data->player_view_direction_y);
		printf("cal ray_Vecotr Y2 %f\n", data->camera_plane_y * curr_ratio);
		printf("cal ray_Vecotr Y3 %f\n", data->player_view_direction_y + data->camera_plane_y * curr_ratio);

		vectors.delta_vector.x = fabs(1 / vectors.ray_vector.x);
		vectors.delta_vector.y = fabs(1 / vectors.ray_vector.y);
		
		map.x = (int) data -> player_position_x;
		map.y = (int) data -> player_position_y;
		
		set_curr_measurement_vector(&map, data, &step, &vectors);
		move_ray(&vectors, &map, data, step);
		vertical_distance = calculate_vertical_distance_from_camera_to_wall(map, data, vectors, step);
		draw_image(vertical_distance, &map, data, &vectors, x);
		x++;
	}
	return (0);
}

void	draw(t_data *data)
{
	for (int y = 0; y < WIN_HEIGHT; y++)
	{
		for (int x = 0; x < WIN_WIDTH; x++)
		{
			// printf("draw value : %d y %d x %d\n", data->buf[y][x], y, x);
			data->img.texture[y * WIN_WIDTH + x] = data->buf[y][x];
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
}

void buffer_initialize(t_data *data)
{
	int y;
	int x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			// printf("y : %d x : %d\n", y, x);
			data->buf[y][x] = 0;
			x++;
		}
		y++;
	}
}

int play(t_data *data)
{
	buffer_initialize(data);
	set_wall(data);
	draw(data);
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == KEYCODE_UP)
	{
		if (!worldMap[(int)(data->player_position_x + data->player_view_direction_x * data->move_speed)][(int)(data->player_position_y)])
			data->player_position_x += data->player_view_direction_x * data->move_speed;
		if (!worldMap[(int)(data->player_position_x)][(int)(data->player_position_y + data->player_view_direction_y * data->move_speed)])
			data->player_position_y += data->player_view_direction_y * data->move_speed;
	}
	//move backwards if no wall behind you
	if (key == KEYCODE_DOWN)
	{
		if (!worldMap[(int)(data->player_position_x - data->player_view_direction_x * data->move_speed)][(int)(data->player_position_y)])
			data->player_position_x -= data->player_view_direction_x * data->move_speed;
		if (!worldMap[(int)(data->player_position_x)][(int)(data->player_position_y - data->player_view_direction_y * data->move_speed)])
			data->player_position_y -= data->player_view_direction_y * data->move_speed;
	}
	//rotate to the right
	if (key == KEYCODE_RIGHT)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = data->player_view_direction_x;
		data->player_view_direction_x = data->player_view_direction_x * cos(-data->rotate_speed) - data->player_view_direction_y * sin(-data->rotate_speed);
		data->player_view_direction_y = oldDirX * sin(-data->rotate_speed) + data->player_view_direction_y * cos(-data->rotate_speed);
		double oldPlaneX = data->camera_plane_x;
		data->camera_plane_x = data->camera_plane_x * cos(-data->rotate_speed) - data->camera_plane_y * sin(-data->rotate_speed);
		data->camera_plane_y = oldPlaneX * sin(-data->rotate_speed) + data->camera_plane_y * cos(-data->rotate_speed);
	}
	//rotate to the left
	if (key == KEYCODE_LEFT)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = data->player_view_direction_x;
		data->player_view_direction_x = data->player_view_direction_x * cos(data->rotate_speed) - data->player_view_direction_y * sin(data->rotate_speed);
		data->player_view_direction_y = oldDirX * sin(data->rotate_speed) + data->player_view_direction_y * cos(data->rotate_speed);
		double oldPlaneX = data->camera_plane_x;
		data->camera_plane_x = data->camera_plane_x * cos(data->rotate_speed) - data->camera_plane_y * sin(data->rotate_speed);
		data->camera_plane_y = oldPlaneX * sin(data->rotate_speed) + data->camera_plane_y * cos(data->rotate_speed);
	}
	if (key == KEYCODE_ESC)
		exit(0);
	mlx_clear_window(data->mlx, data->win);
	play(data);
	return (0);
}

void set_textures(t_data *data)
{
	printf("texture0\n");
	set_texture(data, "texture/eagle.xpm", 0);
	printf("texture1\n");
	set_texture(data, WEST_PATH, WEST);
	printf("texture2\n");
	set_texture(data, EAST_PATH, EAST);
	printf("texture3\n");
	set_texture(data, NORTH_PATH, NORTH);
	printf("texture4\n");
	set_texture(data, SOUTH_PATH, SOUTH);
	printf("texture5\n");
	set_texture(data, "texture/mossy.xpm", FLOOR);
	printf("texture6\n");
	set_texture(data, "texture/wood.xpm", CEILING);
	printf("texture7\n");
	set_texture(data, "texture/colorstone.xpm", 7);
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

