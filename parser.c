/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:51:10 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/29 20:56:25 by minjeon2         ###   ########.fr       */
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
		exit(1);
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

int	make_color(char *line)
{
	int	color;

	color = 0;
	while (*line && *line != '\n')
	{
		if (*line == ',')
		{
			line++;
			continue ;
		}
		if (ft_isdigit(*line))
			color += (int) *line;
		else
			exit(1);
		line++;
	}
	return (color);
}

void	set_floor_and_ceiling_color(char *line, t_args *args)
{
	if (CEILING == check_direction(line))
	{
		line++;
		while (is_whitespace(*line))
			line++;
		args -> ceiling_color = make_color(line);
		return ;
	}
	if (FLOOR == check_direction(line))
	{
		line++;
		while (is_whitespace(*line))
			line++;
		args -> floor_color = make_color(line);
		return ;
	}
}

void	set_direction(char *line, t_args *args)
{
	if (EAST == check_direction(line))
	{
		pass_white_space(&line);
		args->east_path = malloc (ft_strlen(line) + 1);
		copy_path(EAST, line, args, 0);
		return ;
	}
	if (WEST == check_direction(line))
	{
		pass_white_space(&line);
		args->west_path = malloc (ft_strlen(line) + 1);
		copy_path(WEST, line, args, 0);
		return ;
	}
	if (SOUTH == check_direction(line))
	{
		pass_white_space(&line);
		args->south_path = malloc (ft_strlen(line) + 1);
		copy_path(SOUTH, line, args, 0);
		return ;
	}
	if (NORTH == check_direction(line))
	{
		pass_white_space(&line);
		args->north_path = malloc (ft_strlen(line) + 1);
		copy_path(NORTH, line, args, 0);
		return ;
	}
}

char	*ft_char_malloc(size)
{
	char	*return_value;

	return_value = malloc (sizeof(char) * size);
	if (!return_value)
		exit(1);
	return (return_value);
}

void	make_map_rectangular(t_args *args)
{
	int		i;
	int		j;
	char	*new_map_line;
	
	i = 0;
	while (i < args -> y_max)
	{
		if ((int) ft_strlen(args -> map.map[i]) < args -> x_max - 1)
		{
			j = 0;
			new_map_line = ft_char_malloc(args -> x_max);
			while (j < (int) ft_strlen(args -> map.map[i]) - 1)
			{
				new_map_line[j] = args -> map.map[i][j];
				j++;
			}
			while (j < args -> x_max - 1)
			{
				new_map_line[j] = ' ';
				j++;
			}
			new_map_line[j] = '\0';
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
			printf("%d %s\n",i,line);
			if (args -> map.size >= i)
				ft_realloc(args);
			i++;
			line = get_next_line(fd);
		}
		args->map.map[i] = NULL;
		args -> y_max = i;
}

void	parse_argv(t_args *args, int argc, char **argv)
{
	char 	*line;
	int		fd;

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
		set_floor_and_ceiling_color(line, args);
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
		while (only_whitespace(line))
			line = get_next_line(fd);
	}
	args -> map.map= ft_char_two_pointer_malloc(20);
	args -> map.size = 20;
	line = get_next_line(fd);
	while (only_whitespace(line))
			line = get_next_line(fd);
	set_map(fd, args, line); 
	make_map_rectangular(args);

	// for (int i = 0; args -> map.map[i]; i++)
	// {
	// 	printf("%d ", i%10);
	// 	for (int j = 0; args -> map.map[i][j] || args -> map.map[i][j] == '\n'; j++)
	// 	{
	// 		if (args -> map.map[i][j] == ' ')
	// 		{
	// 			printf("2");
	// 		}
	// 		else
	// 			printf("%c", args -> map.map[i][j]);
	// 	}
	// 	printf("\n");
	// }
}
