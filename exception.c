/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:55:58 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/02 18:24:10 by minjeon2         ###   ########.fr       */
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

int	is_wrapped_by_wall(t_args *args)
{
	if (!is_space_in_contact_with_wall(args))
		return (FALSE);
	return (TRUE);
}

int	is_no_texture(t_args *args)
{
	if (args -> north_path == NULL)
		return (TRUE);
	if (args -> south_path == NULL)
		return (TRUE);
	if (args -> west_path == NULL)
		return (TRUE);
	if (args -> east_path == NULL)
		return (TRUE);
	return (FALSE);
}

int	is_not_set_ceiling_or_floor_color(t_args *args)
{
	if (args -> ceiling_color.r == -1 || \
	args -> ceiling_color.g == -1 || \
	args -> ceiling_color.b == -1)
		return (TRUE);
	if (args -> floor_color.r == -1 || \
	args -> floor_color.g == -1 || \
	args -> floor_color.b == -1)
		return (TRUE);
	return (FALSE);
}

int	arr_size_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	is_all_digit(char *color)
{
	while(*color)
	{
		if (!ft_isdigit(*color))
			return (FALSE);
		color++;
	}
	return (TRUE);
}

int	is_in_range(char *color)
{
	if (ft_strlen(color) > 3)
		return (FALSE);
	if (!(0 <= ft_atoi(color) && ft_atoi(color) <= 255))
		return (FALSE);
	return (TRUE);
}

int	is_correct_rgb_color(char *line)
{
	int		i;
	char	**color;

	i = 0;
	color = ft_split(line, ',');
	if (arr_size_len(color) != 3)
		return (FALSE);
	while (i < 3)
	{
		if (!is_all_digit(color[i]))
			return (FALSE);
		if (!is_in_range(color[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int is_next_line_is_map(char *line)
{
	int	curr_direction;

	curr_direction = check_direction(line);
	if (curr_direction == CEILING || curr_direction == FLOOR || curr_direction == NORTH || \
		curr_direction == SOUTH || curr_direction == WEST || curr_direction == EAST)
		return (FALSE);
	return (TRUE);
}