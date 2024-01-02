/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:20:51 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/02 18:23:21 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_correct_map_component(char comp)
{
	if (comp == '1' || comp == '0' || comp == 'N' || \
		comp == 'W' || comp == 'E' || comp == 'S' || comp == ' ' || \
		comp == '2' || comp == '3' || comp == '4' || comp == '5')
		return (TRUE);
	return (FALSE);
}

int	is_correct_map_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] && line[i] != '\n')
	{
		if (!is_correct_map_component(line[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	is_correct_user_position(t_args *args)
{
	int	i;
	int	j;
	int	user_position;

	i = 0;
	user_position = FALSE;
	while (i < args -> y_max)
	{
		j = 0;
		while (j < args -> x_max)
		{
			if (args -> map.map[i][j] == 'N' || args -> map.map[i][j] == 'S' ||\
				args -> map.map[i][j] == 'W' || args -> map.map[i][j] == 'E')
			{
				if (user_position)
					return (FALSE);
				user_position = TRUE;
			}
			j++;
		}
		i++;
	}
	if (!user_position)
		return (FALSE);
	return (TRUE);
}
