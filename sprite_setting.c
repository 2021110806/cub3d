/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_setting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:27:34 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/04 18:27:36 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_sprite_relative_distance(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->args.sprite_count)
	{
		data->args.sprite_information[index].relative_distance = \
		(pow(data->player_position_x - \
		data->args.sprite_information[index].x, 2) + \
		pow(data->player_position_y \
		- data->args.sprite_information[index].y, 2));
		index++;
	}
}

void	setting_transform_coordinate(t_data *data, int index, \
t_sprite_drawing_factors *drawing_factor)
{
	double	relative_x;
	double	relative_y;
	double	inverse_determinant;

	relative_x = data->args.sprite_information[index].x - \
	data->player_position_x;
	relative_y = data->args.sprite_information[index].y - \
	data->player_position_y;
	inverse_determinant = 1.0 / \
	(data->camera_plane_x * data->player_view_direction_y - \
	data->player_view_direction_x * data->camera_plane_y);
	drawing_factor->transform_x = -(inverse_determinant * \
	(data->player_view_direction_y * \
	relative_x - data->player_view_direction_x * relative_y));
	drawing_factor->transform_y = inverse_determinant * \
	(-data->camera_plane_y * relative_x + data->camera_plane_x * relative_y);
	drawing_factor->sprite_screen_x = (int)((WIN_WIDTH / 2) * \
	(1 + drawing_factor->transform_x / drawing_factor->transform_y));
}

void	setting_sprite_draw_height(t_sprite_drawing_factors \
*sprite_drawing_factor, t_data *data)
{
	int	sprite_y_position;

	sprite_y_position = (int)((SPRITE_Z - (data->time - 10)) / \
	sprite_drawing_factor -> transform_y);
	sprite_drawing_factor->sprite_height = \
	abs((int)((WIN_HEIGHT / sprite_drawing_factor->transform_y) / SPRITE_Y));
	sprite_drawing_factor->draw_start_y = \
	-sprite_drawing_factor->sprite_height / 2 + \
	WIN_HEIGHT / 2 + sprite_y_position;
	if (sprite_drawing_factor->draw_start_y < 0)
		sprite_drawing_factor->draw_start_y = 0;
	sprite_drawing_factor->draw_end_y = \
	sprite_drawing_factor->sprite_height / 2 + WIN_HEIGHT / 2 + \
	sprite_y_position;
	if (sprite_drawing_factor->draw_end_y >= WIN_HEIGHT)
		sprite_drawing_factor->draw_end_y = WIN_HEIGHT - 1;
}

void	setting_sprite_draw_width(t_sprite_drawing_factors \
*sprite_drawing_factor)
{
	sprite_drawing_factor->sprite_width = \
	abs((int)((WIN_HEIGHT / sprite_drawing_factor->transform_y) / SPRITE_X));
	sprite_drawing_factor->draw_start_x = \
	-sprite_drawing_factor->sprite_width / 2 \
	+ sprite_drawing_factor->sprite_screen_x;
	if (sprite_drawing_factor->draw_start_x < 0)
		sprite_drawing_factor->draw_start_x = 0;
	sprite_drawing_factor->draw_end_x = sprite_drawing_factor->sprite_width / 2 \
	+ sprite_drawing_factor->sprite_screen_x;
	if (sprite_drawing_factor->draw_end_x >= WIN_WIDTH)
		sprite_drawing_factor->draw_end_x = WIN_WIDTH - 1;
}

void	setting_sprite_animation(t_data *data, int index)
{
	if ((int)(data -> time / 5 == 0))
		data->args.sprite_information[index].image_number = CHICKADEE_1;
	else if ((int)(data -> time / 5 == 1))
		data->args.sprite_information[index].image_number = CHICKADEE_2;
	else if ((int)(data -> time / 5 == 2))
		data->args.sprite_information[index].image_number = CHICKADEE_3;
	else if ((int)(data -> time / 5 == 3))
		data->args.sprite_information[index].image_number = CHICKADEE_4;
	else if ((int)(data -> time / 5 == 4))
		data->time = 0;
}
