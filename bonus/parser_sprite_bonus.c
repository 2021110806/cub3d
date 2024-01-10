/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sprite_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:03:27 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/10 16:16:59 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

	args->sprite_information = ft_sprite_malloc(check_sprite_count(args));
	y = 0;
	args -> sprite_count = 0;
	while (y + 1 < args->y_max)
	{
		x = 0;
		while (x + 2 < args -> x_max)
		{
			if (args->map.map[y][x] == '4')
			{
				args->sprite_information[args->sprite_count] \
				.image_number = CHICKADEE_1;
				args->sprite_information[args->sprite_count].x = x + 0.5;
				args->sprite_information[args->sprite_count].y = y + 0.5;
				args -> sprite_count++;
			}
			x++;
		}
		y++;
	}
}
