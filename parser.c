/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:51:10 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/28 17:14:22 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

int	is_whitespace(char charactor)
{
	if (charactor == ' ' || charactor == '\t' || charactor == '\n' || \
	charactor == 'v' || charactor == '\r')
		return (TRUE);
	return (FALSE);
}

int	only_whitespace(char *line)
{
	while (*line)
	{
		if (is_whitespace(*line))
			line++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	count_line(int fd, char *file_name)
{
	int		count;
	char	*line;

	count = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		count++;
	}
	return (count + 1);
}

char	**ft_char_two_pointer_malloc(int size)
{
	char	**return_value;

	return_value = malloc (sizeof (char *) * size);
	if (!return_value)	
		exit(1);
	return (return_value);
}

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

void	set_direction(char *line, t_args *args)
{
	int		i;
	int		red;
	int		green;
	int		blue;

	red = 0;
	blue = 0;
	green = 0;
	if (EAST == check_direction(line))
	{
		i = 0;
		line++;
		line++;
		while (is_whitespace(*line))
			line++;
		args->east_path = malloc (ft_strlen(line) + 1);
		while (*line && *line != '\n')
		{
			args -> east_path[i] = *line;
			i++;
			line++;
		}
		args -> east_path[i] = '\0';
		return ;
	}
	if (WEST == check_direction(line))
	{
		i = 0;
		line++;
		line++;
		while (is_whitespace(*line))
			line++;
		args->west_path = malloc (ft_strlen(line) + 1);
		while (*line && *line != '\n')
		{
			args -> west_path[i] = *line;
			i++;
			line++;
		}
		args -> west_path[i] = '\0';
		return ;
	}
	if (SOUTH == check_direction(line))
	{
		i = 0;
		line++;
		line++;
		while (is_whitespace(*line))
			line++;
		args->south_path = malloc (ft_strlen(line) + 1);
		while (*line && *line != '\n')
		{
			args -> south_path[i] = *line;
			i++;
			line++;
		}
		args -> south_path[i] = '\0';
		return ;
	}
	if (NORTH == check_direction(line))
	{
		i = 0;
		line++;
		line++;
		while (is_whitespace(*line))
			line++;
		args->north_path = malloc (ft_strlen(line) + 1);
		while (*line && *line != '\n')
		{
			args -> north_path[i] = *line;
			i++;
			line++;
		}
		args -> north_path[i] = '\0';
		return ;
	}
	if (CEILING == check_direction(line))
	{
		line++;
		while (is_whitespace(*line))
			line++;
		while (*line && *line != '\n')
		{
			if (*line == ',')
				break;
			if (ft_isdigit(*line))
				red += (int) *line;
			else
			{
				printf("1\n");
				exit(1);
			}
			line++;
		}
		line ++;
		while (*line && *line != '\n')
		{
			if (*line == ',')
				break;
			if (ft_isdigit(*line))
				green += (int) *line;
			else
			{
				printf("2\n");
				exit(1);
			}
			line++;
		}
		line ++;
		while (*line && *line != '\n')
		{
			if (*line == ',')
				break;
			if (ft_isdigit(*line))
				red += (int) *line;
			else
			{
				printf("3\n");
				exit(1);
			}
			line++;
		}
		args -> ceiling_color = red + green + blue;
		return ;
	}
	if (FLOOR == check_direction(line))
	{
		line++;
		while (is_whitespace(*line))
			line++;
		while (*line && *line != '\n')
		{
			if (*line == ',')
				break;
			if (ft_isdigit(*line))
				red += (int) *line;
			else
			{
				printf("4\n");
				exit(1);
			}
			line++;
		}
		line ++;
		while (*line && *line != '\n')
		{
			if (*line == ',')
				break;
			if (ft_isdigit(*line))
				green += (int) *line;
			else
			{
				printf("5\n");
				exit(1);
			}
			line++;
		}
		line ++;
		while (*line && *line != '\n')
		{
			if (*line == ',')
				break;
			if (ft_isdigit(*line))
				red += (int) *line;
			else
			{
				printf("6\n");
				exit(1);
			}
			line++;
		}
		args -> floor_color = red + green + blue;
		return ;
	}
}

char **ft_realloc(t_args *args)
{
	int		i;
	char	**return_value;

	i = 0;
	return_value = ft_char_two_pointer_malloc(args -> map.size * 2);
	while (i < args -> map.size)
	{
		return_value[i] = args -> map.map[i];
		i++;
	}
	args -> map.map = return_value;
	args -> map.size *= 2;
	return (return_value);
}

void	set_map(int fd, t_args *args)
{
	int	i;
	int	max_len = 0;

	i = 0;
	char *line = get_next_line(fd);
		while (line)
		{
			if (max_len < (int) ft_strlen(line))
				args -> x_max = ft_strlen(line);
			args -> map.map[i] = line;
			if (args -> map.size >= i)
				ft_realloc(args);
			i++;
			line = get_next_line(fd);
		}
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
	set_map(fd, args);
}

// int main(int argc, char **argv)
// {
// 	t_args args;

// 	parse_argv(&args, argc, argv);
// 	int i = 0;
// 	printf("fin - nor %s\n",args.north_path);
// 	printf("fin - sou %s\n",args.south_path);
// 	printf("fin - west %s\n",args.west_path);
// 	printf("fin - east %s\n",args. east_path);
// 	printf("7 floor %d\n", args.floor_color);
// 	printf("8 ceiling %d\n", args.ceiling_color);
// 	while (i < args.y_max)
// 	{
// 		printf("%s\n", args.map.map[i]);
// 		i++;
// 	}
// 	return 0;
// }