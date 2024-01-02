/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_path_bearing.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:01 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/02 19:12:02 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_direction_east_path(char *line, t_args *args)
{
	if (args -> east_path != NULL)
		progrem_error_end(SETTING_FORMAT_ERROR);
	pass_white_space(&line);
	args->east_path = malloc (ft_strlen(line) + 1);
	copy_path(EAST, line, args, 0);
}

void	set_direction_west_path(char *line, t_args *args)
{
	if (args -> west_path != NULL)
		progrem_error_end(SETTING_FORMAT_ERROR);
	pass_white_space(&line);
	args->west_path = malloc (ft_strlen(line) + 1);
	copy_path(WEST, line, args, 0);
}

void	set_direction_south_path(char *line, t_args *args)
{
	if (args -> west_path != NULL)
		progrem_error_end(SETTING_FORMAT_ERROR);
	pass_white_space(&line);
	args->south_path = malloc (ft_strlen(line) + 1);
	copy_path(SOUTH, line, args, 0);
}

void	set_direction_north_path(char *line, t_args *args)
{
	if (args -> west_path != NULL)
		progrem_error_end(SETTING_FORMAT_ERROR);
	pass_white_space(&line);
	args->north_path = malloc (ft_strlen(line) + 1);
	copy_path(NORTH, line, args, 0);
}
