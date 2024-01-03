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
	if (data->args.map.map[(int)data -> player_position_y][(int)data -> player_position_x] == '4')
	{
		data -> speed_time = 200;
		data -> move_speed = 0.5;
	}
	if (data -> speed_time == 0)
		data -> move_speed = 0.15;
	//printf("1\n");
	check_mouse_rotate(data);
	//printf("2\n");
	draw_floor_and_ceiling(data);
	//printf("3\n");
	draw_wall(data);
	//printf("4\n");
	draw_sprite(data);
	//printf("5\n");
	draw_minimap(data);
	//printf("6\n");
	draw_buf(data);
	data -> time++;
	if (data -> speed_time > 0)
		data -> speed_time--;
	//printf("7\n");
	return (0);
}

void	leaks(void)
{
	system("leaks cub3d");
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	// atexit(leaks);
	data.time = 0;
	data.speed_time = 0;
	if (argc != 2)
		program_error_end(ARGUMENT_ERROR);
	i = 0;
	data.mlx = mlx_init();
	parse_argv(&(data.args), argc, argv);
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
	mlx_hook(data.win, RED_BUTTON, 0, &program_end, 0);
	mlx_loop(data.mlx);
}
