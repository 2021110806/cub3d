/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_print_setting_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:27:20 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/10 16:17:18 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	calculate_texture_x(int stripe, \
t_sprite_drawing_factors sprite_drawing_factor)
{
	return ((int)(((stripe - (-sprite_drawing_factor.sprite_width / 2 + \
	sprite_drawing_factor.sprite_screen_x)) * \
	SPRITE_TEXTURE_WIDTH / sprite_drawing_factor.sprite_width)));
}

int	calculate_texture_y(int y, int sprite_z_position, \
t_sprite_drawing_factors sprite_drawing_factor)
{
	int	vertical_offset;

	vertical_offset = (y - sprite_z_position) - WIN_HEIGHT / 2 + \
	sprite_drawing_factor.sprite_height / 2;
	return (((vertical_offset * SPRITE_TEXTURE_HEIGHT) / \
	sprite_drawing_factor.sprite_height));
}

int	is_not_transparent_color(t_data *data, int index, int texture_y, \
int texture_x)
{
	if ((data->texture[data->args.sprite_information[index].image_number] \
	[SPRITE_TEXTURE_WIDTH * texture_y + texture_x] & 0x00FFFFFF) != 0)
		return (TRUE);
	return (FALSE);
}

int	is_printable_sprite(t_data *data, \
t_sprite_drawing_factors sprite_drawing_factor, int stripe)
{
	return (sprite_drawing_factor.transform_y > 0 && stripe > 0 && \
	stripe < WIN_WIDTH && \
	sprite_drawing_factor.transform_y < data->sprite_buffer[stripe]);
}

void	draw_sprite_for_buffer(t_data *data, \
t_sprite_drawing_factors sprite_drawing_factor, \
int sprite_z_position, int index)
{
	int	stripe;
	int	y;
	int	texture_x;
	int	texture_y;

	stripe = sprite_drawing_factor.draw_start_x;
	while (stripe < sprite_drawing_factor.draw_end_x)
	{
		y = sprite_drawing_factor.draw_start_y;
		texture_x = calculate_texture_x(stripe, sprite_drawing_factor);
		if (is_printable_sprite(data, sprite_drawing_factor, stripe))
		{
			while (y < sprite_drawing_factor.draw_end_y)
			{
				texture_y = calculate_texture_y(y, sprite_z_position, \
				sprite_drawing_factor);
				if (is_not_transparent_color(data, index, texture_y, texture_x))
					data->buf[y][stripe] = data->texture[data->args.\
					sprite_information[index].image_number] \
					[SPRITE_TEXTURE_WIDTH * texture_y + texture_x];
				y++;
			}
		}
		stripe++;
	}
}
