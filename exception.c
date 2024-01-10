/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:55:58 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/10 14:27:17 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_start_with_correct_charactor(char *line)
{
	if (ft_strlen(line) < 4)
		return (FALSE);
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (TRUE);
	if (line[0] == 'S' && line[1] == 'O' && line[3] == ' ')
		return (TRUE);
	if (line[0] == 'W' && line[1] == 'E' && line[3] == ' ')
		return (TRUE);
	if (line[0] == 'E' && line[1] == 'A' && line[3] == ' ')
		return (TRUE);
	if (line[0] == 'F' && line[1] == ' ')
		return (TRUE);
	if (line[1] == 'C' && line[1] == ' ')
		return (TRUE);
	return (FALSE);
}

void	is_wrapped_by_wall(t_args *args)
{
	if (!is_space_in_contact_with_wall(args))
		program_error_end(MAP_ERROR);
	if (is_map_edge_check(args))
		program_error_end(MAP_ERROR);
}

void	is_no_texture(t_args *args)
{
	if (args -> north_path == NULL)
		program_error_end(TEXTURE_ERROR);
	if (args -> south_path == NULL)
		program_error_end(TEXTURE_ERROR);
	if (args -> west_path == NULL)
		program_error_end(TEXTURE_ERROR);
	if (args -> east_path == NULL)
		program_error_end(TEXTURE_ERROR);
}

void	is_not_set_ceiling_or_floor_color(t_args *args)
{
	if (args -> ceiling_color.r == -1 || \
	args -> ceiling_color.g == -1 || \
	args -> ceiling_color.b == -1)
		program_error_end(COLOR_ERROR);
	if (args -> floor_color.r == -1 || \
	args -> floor_color.g == -1 || \
	args -> floor_color.b == -1)
		program_error_end(COLOR_ERROR);
}

void	is_next_line_is_map(int fd, char **line)
{
	int		curr_direction;

	*line = get_next_line(fd);
	while (only_whitespace(*line))
	{
		free(*line);
		*line = get_next_line(fd);
	}
	curr_direction = check_direction(*line);
	if (curr_direction == CEILING || curr_direction == FLOOR || \
	curr_direction == NORTH || curr_direction == SOUTH || \
	curr_direction == WEST || curr_direction == EAST)
		program_error_end(SETTING_FORMAT_ERROR);
}
