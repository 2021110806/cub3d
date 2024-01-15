/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_command_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:38:47 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/11 21:40:25 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_movable(t_data *data, double move_x, double move_y)
{
	double	user_size_arr[2];
	int		index;
	int		result_x;
	int		result_y;

	user_size_arr[0] = USER_SIZE;
	user_size_arr[1] = -USER_SIZE;
	index = 0;
	while (index < 2)
	{
		result_x = move_x + user_size_arr[index];
		result_y = move_y + user_size_arr[index];
		if (data->args.map.map[result_y][(int)move_x] == MINIMAP_CLOSE_DOOR || \
		data->args.map.map[result_y][(int)move_x] == MINIMAP_WALL || \
		data->args.map.map[result_y][(int)move_x] == MINIMAP_NULL || \
		data->args.map.map[(int)move_y][result_x] == MINIMAP_CLOSE_DOOR || \
		data->args.map.map[(int)move_y][result_x] == MINIMAP_WALL || \
		data->args.map.map[(int)move_y][result_x] == MINIMAP_NULL)
			return (FALSE);
		index++;
	}
	return (TRUE);
}

void	move_up(t_data *data)
{
	double	move_x;
	double	move_y;

	move_x = data->player_position_x + data->player_view_direction_x * \
	data->move_speed;
	move_y = data->player_position_y + data->player_view_direction_y * \
	data->move_speed;
	if (check_movable(data, move_x, move_y))
	{
		data->player_position_x = move_x;
		data->player_position_y = move_y;
	}
}

void	move_down(t_data *data)
{
	double	move_x;
	double	move_y;

	move_x = data->player_position_x - data->player_view_direction_x * \
	data->move_speed;
	move_y = data->player_position_y - data->player_view_direction_y * \
	data->move_speed;
	if (check_movable(data, move_x, move_y))
	{
		data->player_position_x = move_x;
		data->player_position_y = move_y;
	}
}

void	move_left(t_data *data)
{
	double	move_x;
	double	move_y;

	move_x = data->player_position_x + data->camera_plane_x * data->move_speed;
	move_y = data->player_position_y + data->camera_plane_y * data->move_speed;
	if (check_movable(data, move_x, move_y))
	{
		data->player_position_x = move_x;
		data->player_position_y = move_y;
	}
}

void	move_right(t_data *data)
{
	double	move_x;
	double	move_y;

	move_x = data->player_position_x - data->camera_plane_x * data->move_speed;
	move_y = data->player_position_y - data->camera_plane_y * data->move_speed;
	if (check_movable(data, move_x, move_y))
	{
		data->player_position_x = move_x;
		data->player_position_y = move_y;
	}
}
