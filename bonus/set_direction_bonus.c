/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_direction_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 20:10:41 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/10 16:17:09 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_player_direction_north(t_data *data)
{
	data -> player_view_direction_x = 0.0;
	data -> player_view_direction_y = -1.0;
	data -> camera_plane_x = -0.66;
	data -> camera_plane_y = 0;
}

void	set_player_direction_south(t_data *data)
{
	data -> player_view_direction_x = 0.0;
	data -> player_view_direction_y = 1.0;
	data -> camera_plane_x = 0.66;
	data -> camera_plane_y = 0;
}

void	set_player_direction_west(t_data *data)
{
	data -> player_view_direction_x = -1.0;
	data -> player_view_direction_y = 0.0;
	data -> camera_plane_x = 0.0;
	data -> camera_plane_y = 0.66;
}

void	set_player_direction_east(t_data *data)
{
	data -> player_view_direction_x = 1.0;
	data -> player_view_direction_y = 0.0;
	data -> camera_plane_x = 0.0;
	data -> camera_plane_y = -0.66;
}

void	set_player_direction(t_data *data, char direction)
{
	if (direction == 'N')
		set_player_direction_north(data);
	else if (direction == 'S')
		set_player_direction_south(data);
	else if (direction == 'E')
		set_player_direction_east(data);
	else if (direction == 'W')
		set_player_direction_west(data);
}
