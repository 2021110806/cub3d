/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:52:59 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/30 22:53:17 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_direction(char *line, t_args *args)
{
	if (EAST == check_direction(line))
	{
		if (args -> east_path != NULL)
			exit(1);
		pass_white_space(&line);
		args->east_path = malloc (ft_strlen(line) + 1);
		copy_path(EAST, line, args, 0);
		return ;
	}
	if (WEST == check_direction(line))
	{
		if (args -> west_path != NULL)
			exit(1);
		pass_white_space(&line);
		args->west_path = malloc (ft_strlen(line) + 1);
		copy_path(WEST, line, args, 0);
		return ;
	}
	if (SOUTH == check_direction(line))
	{
		if (args -> west_path != NULL)
			exit(1);
		pass_white_space(&line);
		args->south_path = malloc (ft_strlen(line) + 1);
		copy_path(SOUTH, line, args, 0);
		return ;
	}
	if (NORTH == check_direction(line))
	{
		if (args -> west_path != NULL)
			exit(1);
		pass_white_space(&line);
		args->north_path = malloc (ft_strlen(line) + 1);
		copy_path(NORTH, line, args, 0);
		return ;
	}
	if (CEILING == check_direction(line))
	{
		if (!(args -> ceiling_color.r == -1 && args -> ceiling_color.g == -1 && args -> ceiling_color.b == -1))
			exit(1);
		line++;
		while (is_whitespace(*line))
			line++;
		set_rgb_color(&(args ->ceiling_color) , make_color(&line), make_color(&line), make_color(&line));
		return ;
	}
	if (FLOOR == check_direction(line))
	{
		if (!(args -> floor_color.r == -1 && args -> floor_color.g == -1 && args -> floor_color.b == -1))
			exit(1);
		line++;
		while (is_whitespace(*line))
			line++;
		set_rgb_color(&(args ->floor_color), make_color(&line), make_color(&line), make_color(&line));
		return ;
	}
}
