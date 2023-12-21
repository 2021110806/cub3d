#include "cub3d.h"

void	draw_floor_and_ceiling(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				data->buf[y][x] = 123123 & 8355711;
			else
				data->buf[y][x] = 10000001;
			x++;
		}
		y++;
	}
}

void draw_image(double vertical_distance, t_int_coordinate *map, t_data *data, t_vectors *vectors, int x)
{
	t_drawing_factors drawing_factors;
	int	texture_x;
	int	y;
	double delta;

	drawing_factors.line_height = WIN_HEIGHT / vertical_distance;
	drawing_factors.draw_start = calculate_draw_start(drawing_factors.line_height);
	drawing_factors.draw_end = calculate_draw_end(drawing_factors.line_height);
	drawing_factors.texture_number = worldMap[map -> y][map -> x];
	delta = (1.0 * TEXTURE_HEGIHT / drawing_factors.line_height);
	drawing_factors.curr_drawing_spot = (drawing_factors.draw_start - WIN_HEIGHT / 2 + drawing_factors.line_height / 2) * delta;
	drawing_factors.wall_crash_spot = calculate_wall_crash_spot(data, vertical_distance, vectors);
	texture_x = calculate_texture_spot(data, vectors, drawing_factors.wall_crash_spot);

	y = drawing_factors.draw_start;
	while (y < drawing_factors.draw_end)
	{
		int texture_y = (int) drawing_factors.curr_drawing_spot & (TEXTURE_HEGIHT - 1);
		drawing_factors.curr_drawing_spot += delta;
		//printf("texture_number %d y %lld x %d answer %lld\n", drawing_factors.texture_number, texture_y, texture_x, TEXTURE_HEGIHT * texture_y + texture_x);
		int color = data -> texture[drawing_factors.texture_number][TEXTURE_HEGIHT * texture_y + texture_x];
		if (data->last_hit_pos == Y)
			color = (color >> 1) & 8355711;
		data -> buf[y][x] = color;
		y++;
	}
}

void	draw(t_data *data)
{
	for (int y = 0; y < WIN_HEIGHT; y++)
	{
		for (int x = 0; x < WIN_WIDTH; x++)
			data->img.texture[y * WIN_WIDTH + x] = data->buf[y][x];
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
}