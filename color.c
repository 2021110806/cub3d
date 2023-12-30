/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 16:56:08 by minkyole          #+#    #+#             */
/*   Updated: 2023/12/27 16:56:11 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
