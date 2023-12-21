/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:05:13 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/21 20:38:55 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture(t_data *data, char *direction, int index)
{
	int				i;
	int				j;
	t_image_info	img;

	i = 0;
	img.image = mlx_xpm_file_to_image(data -> mlx, \
	direction, &img.width, &img.height);
	img.texture = (int *) mlx_get_data_addr(img.image, \
	&img.bit_per_pixel, &img.size, &img.endian);
	while (i < img.height)
	{
		j = 0;
		while (j < img.width)
		{
			data -> texture[index][img.width * i + j] = \
			img.texture[img.width * i + j];
			j++;
		}
		i++;
	}
	mlx_destroy_image(data -> mlx, img.image);
}

int	init_buf(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < WIN_HEIGHT)
	{
		while (j < WIN_WIDTH)
		{
			data -> buf[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

void	init_data(t_data *data)
{
	data = malloc(sizeof (data));
	if (!data)
		exit(-1);
}

void	set_player(t_data *data)
{
	data -> player_position_x = 22.0;
	data -> player_position_y = 11.5;
	data -> player_view_direction_x = -1.0;
	data -> player_view_direction_y = 0.0;
	data -> camera_plane_x = 0.0;
	data -> camera_plane_y = 0.66;
	data -> move_speed = 0.15;
	data -> rotate_speed = 0.10;
}
