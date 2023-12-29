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

    mlx_mouse_get_pos(data->win, &current_mouse_x, &current_mouse_y);
    if (current_mouse_x > WIN_WIDTH / 2)
        move_right(data, data->rotate_speed / 3);
    else if (current_mouse_x < WIN_WIDTH / 2)
        move_left(data, data->rotate_speed / 3);
    mlx_mouse_move(data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);

}
