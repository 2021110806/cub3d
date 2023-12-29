/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:25:10 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/29 22:10:19 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	play(t_data *data)
{
	check_mouse_rotate(data);
	draw_floor_and_ceiling(data);
	draw_wall(data);
	draw_minimap(data);
	draw_buf(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	data.mlx = mlx_init();
	parse_argv(&(data.args), argc, argv);
	set_player(&data);
	init_buf(&data);
	mlx_mouse_hide();
	data.texture = ft_int_pointer_malloc(4);
	while (i < 4)
		data .texture[i++] = ft_int_malloc(TEXTURE_HEGIHT * TEXTURE_WIDTH);
	set_textures(&data);
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, GAME_NAME);
	data.img.image = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.img.texture = (int *) mlx_get_data_addr \
	(data.img.image, &data.img.bit_per_pixel, &data.img.size, &data.img.endian);
	mlx_loop_hook(data.mlx, play, &data);
	mlx_hook(data.win, KEY_PRESS_EVENT, 0, &key_press, &data);
	mlx_hook(data.win, RED_BUTTON, 0, &progrem_end, 0);
	mlx_loop(data.mlx);
}
