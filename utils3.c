/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:10:45 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/04 17:21:34 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite	*ft_sprite_malloc(int size)
{
	t_sprite	*return_value;

	return_value = malloc (sizeof(t_sprite) * size);
	if (!return_value)
		exit(-1);
	return (return_value);
}

void	change_move_and_rotate_speed(t_data *data)
{
	if (data->args.map.map[(int)data -> \
	player_position_y][(int)data -> player_position_x] == '4')
	{
		data -> speed_time = 200;
		data -> move_speed = 0.4;
		data -> rotate_speed = 0.2;
	}
	if (data -> speed_time == 0)
	{
		data -> rotate_speed = 0.1;
		data -> move_speed = 0.15;
	}
}
