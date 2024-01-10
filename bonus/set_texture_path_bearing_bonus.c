/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_path_bearing_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:01 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/10 16:17:12 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_direction_east_path(char *line, t_args *args)
{
	if (args -> east_path != NULL)
		program_error_end(SETTING_FORMAT_ERROR);
	pass_white_space(&line);
	args->east_path = malloc (ft_strlen(line) + 1);
	copy_path(EAST, line, args, 0);
}

void	set_direction_west_path(char *line, t_args *args)
{
	if (args -> west_path != NULL)
		program_error_end(SETTING_FORMAT_ERROR);
	pass_white_space(&line);
	args->west_path = malloc (ft_strlen(line) + 1);
	copy_path(WEST, line, args, 0);
}

void	set_direction_south_path(char *line, t_args *args)
{
	if (args -> south_path != NULL)
		program_error_end(SETTING_FORMAT_ERROR);
	pass_white_space(&line);
	args->south_path = malloc (ft_strlen(line) + 1);
	copy_path(SOUTH, line, args, 0);
}

void	set_direction_north_path(char *line, t_args *args)
{
	if (args -> north_path != NULL)
		program_error_end(SETTING_FORMAT_ERROR);
	pass_white_space(&line);
	args->north_path = malloc (ft_strlen(line) + 1);
	copy_path(NORTH, line, args, 0);
}
