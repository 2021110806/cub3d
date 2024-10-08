/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:56:08 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/10 16:15:57 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	rgb_convert_int(t_rgb_color color)
{
	int	convert_rgb;

	convert_rgb = 0;
	convert_rgb += color.r << 16;
	convert_rgb += color.g << 8;
	convert_rgb += color.b;
	return (convert_rgb);
}

void	set_rgb_color(t_rgb_color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

void	color_free(char **color)
{
	int	index;

	index = 0;
	while (color[index])
	{
		free(color[index]);
		index++;
	}
	free(color);
}

int	is_correct_rgb_color(char *line)
{
	int		i;
	char	**color;

	i = 0;
	color = ft_split(line, ',');
	if (arr_size_len(color) != 3)
	{
		color_free(color);
		return (FALSE);
	}
	while (i < 3)
	{
		if (!is_all_digit(color[i]) || !is_in_range(color[i]))
		{
			color_free(color);
			return (FALSE);
		}
		i++;
	}
	color_free(color);
	return (TRUE);
}
