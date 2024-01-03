/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:03:27 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/03 12:03:28 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_sprite_count(t_args *args)
{
	int	y;
	int	x;
	int	sprite_count;

	y = 0;
	sprite_count = 0;
	while (y + 1 < args->y_max)
	{
		x = 0;
		while (x + 2 < args -> x_max)
		{
			if (args->map.map[y][x] == '4')
				sprite_count++;
			x++;
		}
		y++;
	}
	return (sprite_count);
}

void	setting_sprite_information(t_args *args)
{
	int	y;
	int	x;
	int	sprite_count;

	args->sprite_information = ft_sprite_malloc(check_sprite_count(args));
	y = 0;
	sprite_count = 0;
	while (y + 1 < args->y_max)
	{
		x = 0;
		while (x + 2 < args -> x_max)
		{
			if (args->map.map[y][x] == '4')
			{
				args->sprite_information[sprite_count].image_number = CHICKADEE_1;
				args->sprite_information[sprite_count].x = x + 0.5;
				args->sprite_information[sprite_count].y = y + 0.5;
				sprite_count++;
			}
			x++;
		}
		y++;
	}
	args->sprite_count = sprite_count;
}
