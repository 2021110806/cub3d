/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:51:10 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/04 21:12:52 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pass_white_space(char **line)
{
	(*line)++;
	(*line)++;
	while (is_whitespace(**line))
		(*line)++;
}

void	copy_path(int direction, char *line, t_args *args, int i)
{
	if (direction == EAST)
	{
		while (*line && *line != '\n')
			args -> east_path[i++] = *line++;
		args -> east_path[i] = '\0';
	}
	if (direction == WEST)
	{
		while (*line && *line != '\n')
			args -> west_path[i++] = *line++;
		args -> west_path[i] = '\0';
	}
	if (direction == SOUTH)
	{
		while (*line && *line != '\n')
			args -> south_path[i++] = *line++;
		args -> south_path[i] = '\0';
	}
	if (direction == NORTH)
	{
		while (*line && *line != '\n')
			args -> north_path[i++] = *line++;
		args -> north_path[i] = '\0';
	}
}

int	make_color(char **line)
{
	double	color;
	int		i;

	i = 1;
	color = 0;
	while (**line && **line != '\n')
	{
		if (**line == ',')
		{
			(*line)++;
			break ;
		}
		if (ft_isdigit(**line))
		{
			color += ((double) **line - 48) * pow(0.1, i);
			i++;
		}
		else
			program_error_end(COLOR_FORMAT_ERROR);
		(*line)++;
	}
	return ((int)(color * pow(10, i - 1)));
}

void	init_path_and_color(t_args *args)
{
	args -> east_path = NULL;
	args -> west_path = NULL;
	args -> north_path = NULL;
	args -> south_path = NULL;
	args -> ceiling_color.r = -1;
	args -> ceiling_color.g = -1;
	args -> ceiling_color.b = -1;
	args -> floor_color.r = -1;
	args -> floor_color.g = -1;
	args -> floor_color.b = -1;
}

void	parse_argv(t_args *args, char **argv)
{
	int		fd;
	char	*line;

	check_cub_file(argv);
	init_path_and_color(args);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		program_error_end(FILE_ERROR);
	line = set_all_direction(fd, args);
	is_next_line_is_map(fd, &line);
	is_no_texture(args);
	is_not_set_ceiling_or_floor_color(args);
	args -> map.map = ft_char_two_pointer_malloc(20);
	args -> map.size = 20;
	set_map(fd, args, line);
	make_map_rectangular(args);
	is_correct_user_position(args);
	make_space_to_integer(args);
	is_wrapped_by_wall(args);
	setting_sprite_information(args);
}
