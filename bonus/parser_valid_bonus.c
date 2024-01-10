/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_valid_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:26:38 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/10 17:20:57 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_parameter(int argc)
{
	if (argc != 2)
		program_error_end(ARGUMENT_ERROR);
}

void	check_cub_file(char **argv)
{
	if (ft_strlen(argv[1]) < 4)
		program_error_end(FILE_ERROR);
	if (!(argv[1][ft_strlen(argv[1]) - 1] == 'b' && \
	argv[1][ft_strlen(argv[1]) - 2] == 'u' \
	&& argv[1][ft_strlen(argv[1]) - 3] == 'c' && \
	argv[1][ft_strlen(argv[1]) - 4] == '.'))
		program_error_end(FILE_ERROR);
}

void	set_map(int fd, t_args *args, char *line)
{
	int		i;

	i = 0;
	args -> x_max = 0;
	while (only_whitespace(line))
	{
		free (line);
		line = get_next_line(fd);
	}
	while (line)
	{
		if (args -> x_max < (int) ft_strlen(line))
			args -> x_max = (int) ft_strlen(line);
		args -> map.map[i] = line;
		if (args -> map.size >= i)
			ft_realloc(args);
		i++;
		line = get_next_line(fd);
		if (!is_correct_map_line(line))
			program_error_end(MAP_ERROR);
	}
	args->map.map[i] = NULL;
	args -> y_max = i;
}

int	check_direction(char *path)
{	
	if (ft_strlen(path) < 2)
		program_error_end(SETTING_FORMAT_ERROR);
	else
	{
		if (path[0] == 'E' && (path[1] == ' ' || \
		(path[1] == 'A' && path[2] == ' ')))
			return (EAST);
		if (path[0] == 'W' && (path[1] == ' ' || \
		(path[1] == 'E' && path[2] == ' ')))
			return (WEST);
		if (path[0] == 'N' && (path[1] == ' ' || \
		(path[1] == 'O' && path[2] == ' ')))
			return (NORTH);
		if (path[0] == 'S' && (path[1] == ' ' || \
		(path[1] == 'O' && path[2] == ' ')))
			return (SOUTH);
		if (path[0] == 'F' && path[1] == ' ')
			return (FLOOR);
		if (path[0] == 'C' && path[1] == ' ')
			return (CEILING);
	}
	return (-1);
}
