/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 21:42:25 by minkyole          #+#    #+#             */
/*   Updated: 2023/12/29 21:42:26 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_mouse_rotate(t_data *data)
{
    int current_mouse_x;
    int current_mouse_y;

    if (data -> is_mouse_move_active)
    {
        mlx_mouse_get_pos(data->win, &current_mouse_x, &current_mouse_y);
        if (current_mouse_x > WIN_WIDTH / 2)
            move_right(data, data->rotate_speed / 2.5);
        else if (current_mouse_x < WIN_WIDTH / 2)
            move_left(data, data->rotate_speed / 2.5);
        mlx_mouse_move(data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
    }
}

int	check_user_direction(t_data *data, int *check_door_location_x, int *check_door_location_y)
{
    if (double_range_check(data->player_view_direction_x, -1, 0.2) && \
    double_range_check(data->player_view_direction_y, 0, 0.2))
		*check_door_location_x -= 1;
	else if (double_range_check(data->player_view_direction_x, 1, 0.2) && \
	double_range_check(data->player_view_direction_y, 0, 0.2))
		*check_door_location_x += 1;
	else if (double_range_check(data->player_view_direction_x, 0, 0.2) && \
	double_range_check(data->player_view_direction_y, -1, 0.2))
		*check_door_location_y -= 1;
	else if (double_range_check(data->player_view_direction_x, 0, 0.2) && \
	double_range_check(data->player_view_direction_y, 1, 0.2))
		*check_door_location_y += 1;
	else
		return (-1);
	return (1);
}

void    door_open(t_data *data)
{
    int check_door_location_y;
    int check_door_location_x;

    check_door_location_x = data->player_position_x;
    check_door_location_y = data->player_position_y;
    if (check_user_direction(data, &check_door_location_x, &check_door_location_y) == -1)
		return ;
	if (data->args.map.map[check_door_location_y][check_door_location_x] == MINIMAP_CLOSE_DOOR)
	{
        data->args.map.map[check_door_location_y][check_door_location_x] = MINIMAP_OPEN_DOOR;
    }
    else if (data->args.map.map[check_door_location_y][check_door_location_x] == MINIMAP_OPEN_DOOR)
	{
        data->args.map.map[check_door_location_y][check_door_location_x] = MINIMAP_CLOSE_DOOR;
    }
}

void    mouse_active_mode_change(t_data *data)
{
    if (data -> is_mouse_move_active)
    {
        mlx_mouse_show();
        data -> is_mouse_move_active = 0;
    }
    else
    {
        mlx_mouse_hide();
        data -> is_mouse_move_active = 0;
    }
}

int mouse_press(int button, int x, int y, t_data *data)
{
    if (button == MOUSE_LEFT_CLICK)
        door_open(data);
    else if (button == MOUSE_RIGHT_CLICK)
        mouse_active_mode_change(data);
    (void) x;
    (void) y;
    return (0);
}
