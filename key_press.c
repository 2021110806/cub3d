/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 15:24:56 by minkyole          #+#    #+#             */
/*   Updated: 2023/12/23 15:24:57 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_data *data)
{
	if (key == KEYCODE_UP)
		move_up(data);
	if (key == KEYCODE_DOWN)
		move_down(data);
	if (key == KEYCODE_RIGHT)
		move_right(data);
	if (key == KEYCODE_LEFT)
		move_left(data);
	if (key == KEYCODE_ESC)
		exit(0);
	mlx_clear_window(data->mlx, data->win);
	play(data);
	return (0);
}

void	move_up(t_data *data)
{
	if (!worldMap[(int)(data->player_position_x + \
	data->player_view_direction_x * data->move_speed)] \
	[(int)(data->player_position_y)])
			data->player_position_x += \
			data->player_view_direction_x * data->move_speed;
	if (!worldMap[(int)(data->player_position_x)] \
	[(int)(data->player_position_y + data->player_view_direction_y * \
	data->move_speed)])
			data->player_position_y += data->player_view_direction_y * \
			data->move_speed;
}

void	move_down(t_data *data)
{
	if (!worldMap[(int)(data->player_position_x - \
	data->player_view_direction_x * data->move_speed)] \
	[(int)(data->player_position_y)])
			data->player_position_x -= \
			data->player_view_direction_x * data->move_speed;
	if (!worldMap[(int)(data->player_position_x)] \
	[(int)(data->player_position_y - data->player_view_direction_y * \
	data->move_speed)])
			data->player_position_y -= \
			data->player_view_direction_y * data->move_speed;
}

void	move_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player_view_direction_x;
	old_plane_x = data->camera_plane_x;
	data->player_view_direction_x = data->player_view_direction_x \
	* cos(data->rotate_speed) - data->player_view_direction_y \
	* sin(data->rotate_speed);
	data->player_view_direction_y = old_dir_x \
	* sin(data->rotate_speed) + data->player_view_direction_y \
	* cos(data->rotate_speed);
	data->camera_plane_x = data->camera_plane_x \
	* cos(data->rotate_speed) - data->camera_plane_y \
	* sin(data->rotate_speed);
	data->camera_plane_y = old_plane_x \
	* sin(data->rotate_speed) + data->camera_plane_y \
	* cos(data->rotate_speed);
}

void	move_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player_view_direction_x;
	old_plane_x = data->camera_plane_x;
	data->player_view_direction_x = data->player_view_direction_x \
	* cos(-data->rotate_speed) - data->player_view_direction_y \
	* sin(-data->rotate_speed);
	data->player_view_direction_y = old_dir_x \
	* sin(-data->rotate_speed) + data->player_view_direction_y \
	* cos(-data->rotate_speed);
	data->camera_plane_x = data->camera_plane_x \
	* cos(-data->rotate_speed) - data->camera_plane_y \
	* sin(-data->rotate_speed);
	data->camera_plane_y = old_plane_x \
	* sin(-data->rotate_speed) + data->camera_plane_y \
	* cos(-data->rotate_speed);
}
