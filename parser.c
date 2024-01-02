/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:51:10 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/30 22:53:32 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_direction(char *path)
{	
	if (ft_strlen(path) < 2)
		exit (1);
	else
	{
		if (path[0] == 'E' && path[1] == 'A' && is_whitespace(path[2]))
			return (EAST);
		if (path[0] == 'W' && path[1] == 'E' && is_whitespace(path[2]))
			return (WEST);
		if (path[0] == 'N' && path[1] == 'O' && is_whitespace(path[2]))
			return (NORTH);
		if (path[0] == 'S' && path[1] == 'O' && is_whitespace(path[2]))
			return (SOUTH);
		if (path[0] == 'F' && is_whitespace(path[1]))
			return (FLOOR);
		if (path[0] == 'C' && is_whitespace(path[1]))
			return (CEILING);
	}
	return (-1);
}

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
			exit(1);
		(*line)++;
	}
	return ((int)(color * pow(10, i - 1)));
}

char	*ft_char_malloc(size)
{
	char	*return_value;

	return_value = malloc (sizeof(char) * size);
	if (!return_value)
		exit(1);
	return (return_value);
}

void make_space_to_integer(t_args *args)
{
	int	i;
	int	j;

	i = 0;
	while (i < args -> y_max)
	{
		j = 0;
		while (j < args -> x_max)
		{
			if (args -> map.map[i][j] == ' ')
				args -> map.map[i][j] = '5';
			j++;
		}
		i++;
	}
}

void	make_map_rectangular(t_args *args)
{
	int		i;
	int		j;
	char	*new_map_line;

	i = 0;
	while (i < args -> y_max)
	{
		if ((int) ft_strlen(args -> map.map[i]) < args -> x_max)
		{
			j = 0;
			new_map_line = ft_char_malloc(args -> x_max + 1);
			while (j < (int) ft_strlen(args -> map.map[i]) - 1)
			{
				new_map_line[j] = args -> map.map[i][j];
				j++;
			}
			while (j < args -> x_max - 1)
			{
				new_map_line[j] = MINIMAP_NULL;
				j++;
			}
			new_map_line[j] = '\n';
			new_map_line[j + 1] = '\0';
			char *tmp = args -> map.map[i];
			args -> map.map[i] = new_map_line;
			free(tmp);
		}
		i++;
	}	
}


void	set_map(int fd, t_args *args, char *line)
{
	int	i;

	i = 0;
	args -> x_max = 0;
		while (line)
		{
			if (args -> x_max < (int) ft_strlen(line))
				args -> x_max = (int) ft_strlen(line);
			args -> map.map[i] = line;
			if (args -> map.size >= i)
				ft_realloc(args);
			i++;
			line = get_next_line(fd);
			// if (!is_correct_map_line(line))
			// 	exit(1);
		}
		args->map.map[i] = NULL;
		args -> y_max = i;
}

void	parse_argv(t_args *args, int argc, char **argv)
{
	char 	*line;
	int		fd;

	printf("parse start\n");
	if (ft_strlen(argv[1]) < 4)
		exit(1);
	if (!(argv[1][ft_strlen(argv[1]) - 1] == 'b' && argv[1][ft_strlen(argv[1]) - 2] == 'u' \
	&& argv[1][ft_strlen(argv[1]) - 3] == 'c' && argv[1][ft_strlen(argv[1]) - 4] == '.'))
		exit(1);
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
	if (argc > 2)
		exit(1);
	else
	{
		fd = open(argv[1], O_RDONLY);
		line = get_next_line(fd);
		if (fd == -1)
			exit(1);
		while (line && *line && only_whitespace(line))
			line = get_next_line(fd);
		set_direction(line, args);
		line = get_next_line(fd);
		while (only_whitespace(line))
			line = get_next_line(fd);
		set_direction(line, args);
		line = get_next_line(fd);
		while (only_whitespace(line))
			line = get_next_line(fd);
		set_direction(line, args);
		line = get_next_line(fd);
		while (only_whitespace(line))
			line = get_next_line(fd);
		set_direction(line, args);
		line = get_next_line(fd);
		while (only_whitespace(line))
		 	line = get_next_line(fd);
		set_direction(line, args);
		line = get_next_line(fd);
		while (only_whitespace(line))
			line = get_next_line(fd);
		set_direction(line, args);
		line = get_next_line(fd);
		while (only_whitespace(line))
			line = get_next_line(fd);
		if (!is_next_line_is_map(line))
			exit(1);
	}
	if (is_no_texture(args))
		exit(1);
	if (is_not_set_ceiling_or_floor_color(args))
		exit(1);
	args -> map.map= ft_char_two_pointer_malloc(20);
	args -> map.size = 20;
	while (only_whitespace(line))
			line = get_next_line(fd);
	set_map(fd, args, line); 
	make_map_rectangular(args);
	if (!is_correct_user_position(args))
		exit(1);
	make_space_to_integer(args);
	// if (!is_wrapped_by_wall(args))
	// 	exit(1);
	printf("parse end\n");
}
