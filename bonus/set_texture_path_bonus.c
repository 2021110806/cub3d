/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_path_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:52:59 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/10 16:21:05 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_direction_ceiling_path(char *line, t_args *args)
{
	if (!(args -> ceiling_color.r == -1 && args -> ceiling_color.g \
	== -1 && args -> ceiling_color.b == -1))
		program_error_end(SETTING_FORMAT_ERROR);
	line++;
	while (is_whitespace(*line))
		line++;
	if (!is_correct_rgb_color(line))
		program_error_end(COLOR_FORMAT_ERROR);
	set_rgb_color(&(args ->ceiling_color), \
	make_color(&line), make_color(&line), make_color(&line));
}

void	set_direction_floor_path(char *line, t_args *args)
{
	if (!(args -> floor_color.r == -1 && args -> floor_color.g \
	== -1 && args -> floor_color.b == -1))
		program_error_end(SETTING_FORMAT_ERROR);
	line++;
	while (is_whitespace(*line))
		line++;
	if (!is_correct_rgb_color(line))
		program_error_end(COLOR_FORMAT_ERROR);
	if (!is_correct_rgb_color(line))
		program_error_end(COLOR_FORMAT_ERROR);
	set_rgb_color(&(args ->floor_color), make_color(&line), \
	make_color(&line), make_color(&line));
}

void	set_direction(char *line, t_args *args)
{
	if (EAST == check_direction(line))
		set_direction_east_path(line, args);
	else if (WEST == check_direction(line))
		set_direction_west_path(line, args);
	else if (SOUTH == check_direction(line))
		set_direction_south_path(line, args);
	else if (NORTH == check_direction(line))
		set_direction_north_path(line, args);
	else if (CEILING == check_direction(line))
		set_direction_ceiling_path(line, args);
	else if (FLOOR == check_direction(line))
		set_direction_floor_path(line, args);
}

char	*set_all_direction(int fd, t_args *args)
{
	int		repeat_num;
	char	*line;

	repeat_num = 6;
	while (repeat_num > 0)
	{
		line = get_next_line(fd);
		if (!line || !(*line))
			program_error_end(FILE_ERROR);
		while (only_whitespace(line))
		{
			free(line);
			line = get_next_line(fd);
		}
		set_direction(line, args);
		free(line);
		repeat_num--;
	}
	return (line);
}
