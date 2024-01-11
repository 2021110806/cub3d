/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:35:33 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/11 21:36:10 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_data *data)
{
	if (data->args.map.map[(int)(data->player_position_y + \
	data->player_view_direction_y * data->move_speed)] \
	[(int)(data->player_position_x)] != MINIMAP_WALL)
			data->player_position_y += \
			data->player_view_direction_y * data->move_speed;
	if (data->args.map.map[(int)(data->player_position_y)] \
	[(int)(data->player_position_x + data->player_view_direction_x * \
	data->move_speed)] != MINIMAP_WALL)
			data->player_position_x += data->player_view_direction_x * \
			data->move_speed;
}

void	move_down(t_data *data)
{
	if (data->args.map.map[(int)(data->player_position_y - \
	data->player_view_direction_y * data->move_speed)] \
	[(int)(data->player_position_x)] != MINIMAP_WALL)
		data->player_position_y -= \
		data->player_view_direction_y * data->move_speed;
	if (data->args.map.map[(int)(data->player_position_y)] \
	[(int)(data->player_position_x - data->player_view_direction_x * \
	data->move_speed)] != MINIMAP_WALL)
		data->player_position_x -= \
		data->player_view_direction_x * data->move_speed;
}

void	move_left(t_data *data)
{
	if (data->args.map.map[(int)(data->player_position_y + \
	data->camera_plane_y * data->move_speed)] \
	[(int)(data->player_position_x)] != MINIMAP_WALL)
			data->player_position_y += \
			data->camera_plane_y* data->move_speed;
	if (data->args.map.map[(int)(data->player_position_y)] \
	[(int)(data->player_position_x + data->camera_plane_x * \
	data->move_speed)] != MINIMAP_WALL)
			data->player_position_x += data->camera_plane_x * \
			data->move_speed;
}

void	move_right(t_data *data)
{
	if (data->args.map.map[(int)(data->player_position_y - \
	data->camera_plane_y * data->move_speed)] \
	[(int)(data->player_position_x)] != MINIMAP_WALL)
		data->player_position_y -= \
		data->camera_plane_y * data->move_speed;
	if (data->args.map.map[(int)(data->player_position_y)] \
	[(int)(data->player_position_x - data->camera_plane_x * \
	data->move_speed)] != MINIMAP_WALL)
		data->player_position_x -= \
		data->camera_plane_x * data->move_speed;
}
