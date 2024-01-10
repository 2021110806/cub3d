/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:05:13 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/10 17:24:09 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_texture(t_data *data, char *direction, int index)
{
	int				i;
	int				j;
	t_image_info	img;

	i = 0;
	img.image = mlx_xpm_file_to_image(data -> mlx, \
	direction, &img.width, &img.height);
	if (img.image == NULL)
		program_error_end(TEXTURE_ERROR);
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

void	is_player_direction(t_data *data, int y, int x)
{
	if (data->args.map.map[y][x] == 'N' || data->args.map.map[y][x] == 'S' || \
	data->args.map.map[y][x] == 'E' || data->args.map.map[y][x] == 'W')
	{
		set_player_direction(data, data->args.map.map[y][x]);
		data->player_position_y = y + 0.5;
		data->player_position_x = x + 0.5;
		data->args.map.map[y][x] = '0';
	}
}

void	check_player_direction(t_data *data)
{
	int	current_y;
	int	current_x;

	current_y = 0;
	while (data->args.map.map[current_y])
	{
		current_x = 0;
		while (data->args.map.map[current_y][current_x])
		{
			is_player_direction(data, current_y, current_x);
			current_x++;
		}
		current_y++;
	}
}

void	set_player(t_data *data)
{
	check_player_direction(data);
	data -> is_mouse_move_active = 1;
	mlx_mouse_hide();
	data -> move_speed = 0.15;
	data -> rotate_speed = 0.10;
}
