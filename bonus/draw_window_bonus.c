/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:05:34 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/10 16:16:10 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	draw_minimap(t_data *data)
{
	t_minimap_color		minimap_color;
	t_int_coordinate	minimap_coordinate;
	int					current_location;

	minimap_coordinate.y = 0;
	init_minimap_color(&minimap_color);
	while (minimap_coordinate.y < 11)
	{
		minimap_coordinate.x = 0;
		while (minimap_coordinate.x < 11)
		{
			current_location = check_minimap_current_location(\
			minimap_coordinate.y, minimap_coordinate.x, data);
			draw_map_one_space(minimap_coordinate.y * MAP_ONE_SPACE_SIZE, \
			WIN_WIDTH - minimap_coordinate.x * MAP_ONE_SPACE_SIZE, \
			data, check_color(current_location, minimap_color));
			minimap_coordinate.x++;
		}
		minimap_coordinate.y++;
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

void	draw_sprite(t_data *data)
{
	int							index;
	t_sprite_drawing_factors	sprite_drawing_factor;
	int							sprite_z_position;

	index = 0;
	check_sprite_relative_distance(data);
	sort_sprite_information(data);
	while (index < data->args.sprite_count)
	{
		setting_transform_coordinate(data, index, &sprite_drawing_factor);
		sprite_z_position = (int)((SPRITE_Z - (data->time - 10)) / \
		sprite_drawing_factor.transform_y);
		setting_sprite_draw_height(&sprite_drawing_factor, data);
		setting_sprite_draw_width(&sprite_drawing_factor);
		setting_sprite_animation(data, index);
		draw_sprite_for_buffer(data, sprite_drawing_factor, \
		sprite_z_position, index);
		index++;
	}
}
