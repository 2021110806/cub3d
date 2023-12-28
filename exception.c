/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:55:58 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/28 18:36:09 by minjeon2         ###   ########.fr       */
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

int	is_correct_map_component(char comp)
{
	if (comp == '1' || comp == '0' || comp == 'N' || \
		comp == 'W' || comp == 'E' || comp == 'S' || comp == ' ')
		return (TRUE);
	return (FALSE);
}

int	is_correct_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!is_correct_map_component(line[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_wrapped_by_wall(t_args *args)
{
	int	i;

	i = 0;
	while (args -> map.map[0][i] && args -> map.map[0][i] != '\n')
	{
		if (!(args -> map.map[0][i] == '1' || args -> map.map[0][i] == ' '))
			return (FALSE);
		i++;
	}
	i = 0;
	while (args -> map.map[args->y_max - 1][i] && args -> map.map[args->y_max - 1] != '\n')
	{
		if (!(args -> map.map[args->y_max - 1][i] == '1' || args -> map.map[args -> y_max - 1][i] == ' '))
			return (FALSE);
		i++;
	}
	i = 0;
	while (i < args -> y_max)
	{
		if (!(args -> map.map[i][0] == '1' || args -> map.map[i][0] == ' '))
			return (FALSE);
		if (!(args -> map.map[i][ft_strlen(args -> map.map[i])] == '1' || args -> map.map[i][ft_strlen(args -> map.map[i])] == ' '))
			return (FALSE);
	}
	return (TRUE);
}
