/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_structure_validator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:23:50 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/02 18:28:08 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_side_wall_or_null(t_args *args, int y, int x)
{
	if ((args -> map.map[y][x] == MINIMAP_WALL || \
		args -> map.map[y][x] == MINIMAP_NULL))
		return (TRUE);
	return (FALSE);
}

int	is_four_side_wall_or_null(t_args *args, int x, int y)
{
	if (args -> map.map[y][x] == MINIMAP_NULL)
	{
		if (y - 1 > -1)
		{
			if (!is_side_wall_or_null(args, y - 1, x))
				return (FALSE);
		}
		if (y + 1 < args -> y_max)
		{
			if (!is_side_wall_or_null(args, y + 1, x))
				return (FALSE);
		}
		if (x - 1 > -1)
		{
			if (!is_side_wall_or_null(args, y, x - 1))
				return (FALSE);
		}
		if (x + 2 < args -> x_max)
		{
			if (!is_side_wall_or_null(args, y, x + 1))
				return (FALSE);
		}
	}
	return (TRUE);
}

int	is_space_in_contact_with_wall(t_args *args)
{
	int	i;
	int	j;

	i = 0;
	while (i < args -> y_max)
	{
		j = 0;
		while (j < args -> x_max)
		{
			if (!is_four_side_wall_or_null(args, j, i))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
