/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 00:42:28 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/10 15:24:50 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen_nl_map_set(char *line)
{
	int	i;
	int	nl_flag;

	nl_flag = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			nl_flag = 1;
		i++;
	}
	if (nl_flag)
		return (i);
	return (i + 1);
}

void	make_map_rectangular(t_args *args)
{
	int		i;
	int		j;
	char	*new_map_line;
	char	*tmp;

	i = -1;
	while (++i < args -> y_max)
	{
		if ((int) ft_strlen(args -> map.map[i]) < args -> x_max)
		{
			j = -1;
			new_map_line = ft_char_malloc(args -> x_max + 1);
			while (++j < ft_strlen_nl_map_set(args -> map.map[i]) - 1)
				new_map_line[j] = args -> map.map[i][j];
			while (j < args -> x_max - 1)
				new_map_line[j++] = MINIMAP_NULL;
			new_map_line[j] = '\n';
			new_map_line[j + 1] = '\0';
			tmp = args -> map.map[i];
			args -> map.map[i] = new_map_line;
			free(tmp);
		}
	}	
}

void	make_space_to_integer(t_args *args)
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
