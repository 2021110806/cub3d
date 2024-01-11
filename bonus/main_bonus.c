/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:25:10 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/11 21:53:57 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	play(t_data *data)
{
	change_move_and_rotate_speed(data);
	check_mouse_rotate(data);
	draw_floor_and_ceiling(data);
	draw_wall(data);
	draw_sprite(data);
	draw_minimap(data);
	draw_buf(data);
	data -> time++;
	if (data -> speed_time > 0)
		data -> speed_time--;
	return (0);
}

// int	key_release(int key, t_data *data)
// {
// 	(void) data;
// 	printf("ㅋㅋ 밈정바보야 근데 예뻐서 괜찮아 %d\n", key);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	data.time = 0;
	data.speed_time = 0;
	check_parameter(argc);
	i = 0;
	data.mlx = mlx_init();
	parse_argv(&(data.args), argv);
	set_player(&data);
	data.texture = ft_int_pointer_malloc(10);
	while (i < 10)
		data.texture[i++] = ft_int_malloc(TEXTURE_HEGIHT * TEXTURE_WIDTH);
	set_textures(&data);
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, GAME_NAME);
	data.img.image = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.img.texture = (int *) mlx_get_data_addr \
	(data.img.image, &data.img.bit_per_pixel, &data.img.size, &data.img.endian);
	mlx_loop_hook(data.mlx, play, &data);
	mlx_mouse_hook(data.win, mouse_press, &data);
	mlx_hook(data.win, KEY_PRESS_EVENT, 0, &key_press, &data);
	mlx_hook(data.win, 3, 0, &key_release, &data);
	mlx_hook(data.win, RED_BUTTON, 0, &program_end, 0);
	mlx_loop(data.mlx);
}
