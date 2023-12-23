/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 14:51:10 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/23 21:10:43 by minjeon2         ###   ########.fr       */
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
		while (*line)
		{
			args -> east_path[i] = *line;
			i++;
			line++;
		}
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
		while (*line)
		{
			args -> west_path[i] = *line;
			i++;
			line++;
		}
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
		while (*line)
		{
			args -> south_path[i] = *line;
			i++;
			line++;
		}
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
		while (*line)
		{
			args -> north_path[i] = *line;
			i++;
			line++;
		}
		printf("!!!!!!! %s\n", args -> north_path);
		return ;
	}

	if (CEILING == check_direction(line))
	{
		line++;
		while (is_whitespace(*line))
			line++;
		while ((*line) && *line != ',')
		{
			if (ft_isdigit(*line))
				red += (int) *line << 16;
			else
				exit(1);
			line++;
		}
		line ++;
		while ((*line) && *line != ',')
		{
			if (ft_isdigit(*line))
				green += (int) *line << 8;
			else
				exit(1);
			line++;
		}
		line ++;
		while ((*line) && *line != ',' )
		{
			if (ft_isdigit(*line))
				red += (int) *line;
			else
				exit(1);
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
		while ((*line) && *line != ',')
		{
			if (ft_isdigit(*line))
				red += (int) *line << 16;
			else
				exit(1);
			line++;
		}
		line ++;
		while ((*line) && *line != ',')
		{
			if (ft_isdigit(*line))
				green += (int) *line << 8;
			else
				exit(1);
			line++;
		}
		line ++;
		while ((*line) && *line != ',')
		{
			if (ft_isdigit(*line))
				red += (int) *line;
			else
				exit(1);
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
	int	max_len;

	i = 0;
	max_len = 0;
	char *line = get_next_line(fd);
	while (line)
	{
		if (max_len < ft_strlen(line))
			max_len = ft_strlen(line);
		args -> map.map[i] = line;
		line = get_next_line(fd);
		if (args -> map.size >= i)
			ft_realloc(args);
	}
}

void	parse_argv(t_args *args, int argc, char **argv)
{
	char 	*line;
	int		fd;
	int		i;

	if (argc > 2)
		exit(1);
	else
	{
		printf("1\n");
		fd = open(argv[1], O_RDONLY);
		line = get_next_line(fd);
		if (fd == -1)
			exit(1);
		printf("2\n");
		while (line && *line && only_whitespace(line))
			line = get_next_line(fd);
		printf("3 %s\n", line);
		set_direction(line, args);
		printf("%s!!\n", args -> north_path);
		printf("line : %s\n", line);
		line = get_next_line(fd);
		while (only_whitespace(line))
			line = get_next_line(fd);
		printf("4 %s\n", line);
		set_direction(line, args);
		line = get_next_line(fd);
		while (only_whitespace(line))
			line = get_next_line(fd);
		printf("5 %s\n", line);
		set_direction(line, args);
		line = get_next_line(fd);
		while (only_whitespace(line))
			line = get_next_line(fd);
		printf("6 %s\n", line);
		set_direction(line, args);
		line = get_next_line(fd);
		while (only_whitespace(line))
			line = get_next_line(fd);
		set_direction(line, args);
		line = get_next_line(fd);
		while (line  && only_whitespace(line))
			line = get_next_line(fd);
		set_direction(line, args);
		line = get_next_line(fd);
		while (line && only_whitespace(line))
			line = get_next_line(fd);
	}
	printf("fin - nor %s\n",args -> north_path);
	printf("fin - sou %s\n",args -> south_path);
	printf("fin - west %s\n",args -> west_path);
	printf("fin - east %s\n",args -> east_path);
	args -> map.map= ft_char_two_pointer_malloc(20);
	args -> map.size = 20;
	set_map(fd, args);
}

int main(int argc, char **argv)
{
	t_args args;

	parse_argv(&args, argc, argv);
	int i = 0;
	while (i < args.map.size)
	{
		printf("%s\n", args.map.map[i]);
		i++;
	}
	return 0;
}