/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:24:56 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/11 21:42:21 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_key_input(t_data *data)
{
	if (data->current_input_key == KEYCODE_UP)
		move_up(data);
	else if (data->current_input_key == KEYCODE_DOWN)
		move_down(data);
	else if (data->current_input_key == KEYCODE_RIGHT)
		move_right(data);
	else if (data->current_input_key == KEYCODE_LEFT)
		move_left(data);
	else if (data->current_input_key == KEYCODE_ARROW_RIGHT)
		move_arrow_right(data, data->rotate_speed);
	else if (data->current_input_key == KEYCODE_ARROW_LEFT)
		move_arrow_left(data, data->rotate_speed);
}

int	key_press(int key, t_data *data)
{
	data->current_input_key = key;
	if (key == KEYCODE_ESC)
		exit(0);
	return (0);
}

void	move_arrow_left(t_data *data, double rotate_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player_view_direction_x;
	old_plane_x = data->camera_plane_x;
	data->player_view_direction_x = data->player_view_direction_x \
	* cos(-rotate_speed) - data->player_view_direction_y \
	* sin(-rotate_speed);
	data->player_view_direction_y = old_dir_x \
	* sin(-rotate_speed) + data->player_view_direction_y \
	* cos(-rotate_speed);
	data->camera_plane_x = data->camera_plane_x \
	* cos(-rotate_speed) - data->camera_plane_y \
	* sin(-rotate_speed);
	data->camera_plane_y = old_plane_x \
	* sin(-rotate_speed) + data->camera_plane_y \
	* cos(-rotate_speed);
}

void	move_arrow_right(t_data *data, double rotate_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player_view_direction_x;
	old_plane_x = data->camera_plane_x;
	data->player_view_direction_x = data->player_view_direction_x \
	* cos(rotate_speed) - data->player_view_direction_y \
	* sin(rotate_speed);
	data->player_view_direction_y = old_dir_x \
	* sin(rotate_speed) + data->player_view_direction_y \
	* cos(rotate_speed);
	data->camera_plane_x = data->camera_plane_x \
	* cos(rotate_speed) - data->camera_plane_y \
	* sin(rotate_speed);
	data->camera_plane_y = old_plane_x \
	* sin(rotate_speed) + data->camera_plane_y \
	* cos(rotate_speed);
}
