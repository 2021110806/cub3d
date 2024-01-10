/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:54:00 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/02 16:54:00 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	check_minimap_current_location(int y, int x, t_data *data)
{
	int	minimap_y;
	int	minimap_x;

	minimap_y = floor(data->player_position_y) - (5 - y);
	minimap_x = floor(data->player_position_x) + (5 - x);
	if (minimap_y < 0 || minimap_x < 0 || \
	minimap_y >= data->args.y_max || minimap_x >= data->args.x_max - 1)
		return (MINIMAP_NULL);
	if (minimap_y == floor(data->player_position_y) && \
	minimap_x == floor(data->player_position_x))
		return (MINIMAP_PLAYER);
	return (data -> args.map.map[minimap_y][minimap_x]);
}

void	init_minimap_color(t_minimap_color *minimap_color)
{
	set_rgb_color(&minimap_color->null_color, 189, 189, 189);
	set_rgb_color(&minimap_color->player_color, 255, 0, 221);
	set_rgb_color(&minimap_color->empty_color, 183, 240, 177);
	set_rgb_color(&minimap_color->wall_color, 242, 150, 97);
	set_rgb_color(&minimap_color->door_close_color, 153, 112, 0);
	set_rgb_color(&minimap_color->door_open_color, 250, 237, 125);
	set_rgb_color(&minimap_color->chickadee_color, 103, 153, 255);
}

t_rgb_color	check_color(int current_location, t_minimap_color minimap_color)
{
	if (current_location == MINIMAP_WALL)
		return (minimap_color.wall_color);
	else if (current_location == MINIMAP_EMPTY)
		return (minimap_color.empty_color);
	else if (current_location == MINIMAP_PLAYER)
		return (minimap_color.player_color);
	else if (current_location == MINIMAP_CLOSE_DOOR)
		return (minimap_color.door_close_color);
	else if (current_location == MINIMAP_OPEN_DOOR)
		return (minimap_color.door_open_color);
	else if (current_location == MINIMAP_CHICKADEE)
		return (minimap_color.chickadee_color);
	return (minimap_color.null_color);
}
