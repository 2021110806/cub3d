#include "cub3d.h"

int	key_press(int key, t_data *data)
{
	if (key == KEYCODE_UP)
	{
		if (!worldMap[(int)(data->player_position_x + data->player_view_direction_x * data->move_speed)][(int)(data->player_position_y)])
			data->player_position_x += data->player_view_direction_x * data->move_speed;
		if (!worldMap[(int)(data->player_position_x)][(int)(data->player_position_y + data->player_view_direction_y * data->move_speed)])
			data->player_position_y += data->player_view_direction_y * data->move_speed;
	}
	//move backwards if no wall behind you
	if (key == KEYCODE_DOWN)
	{
		if (!worldMap[(int)(data->player_position_x - data->player_view_direction_x * data->move_speed)][(int)(data->player_position_y)])
			data->player_position_x -= data->player_view_direction_x * data->move_speed;
		if (!worldMap[(int)(data->player_position_x)][(int)(data->player_position_y - data->player_view_direction_y * data->move_speed)])
			data->player_position_y -= data->player_view_direction_y * data->move_speed;
	}
	//rotate to the right
	if (key == KEYCODE_RIGHT)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = data->player_view_direction_x;
		data->player_view_direction_x = data->player_view_direction_x * cos(-data->rotate_speed) - data->player_view_direction_y * sin(-data->rotate_speed);
		data->player_view_direction_y = oldDirX * sin(-data->rotate_speed) + data->player_view_direction_y * cos(-data->rotate_speed);
		double oldPlaneX = data->camera_plane_x;
		data->camera_plane_x = data->camera_plane_x * cos(-data->rotate_speed) - data->camera_plane_y * sin(-data->rotate_speed);
		data->camera_plane_y = oldPlaneX * sin(-data->rotate_speed) + data->camera_plane_y * cos(-data->rotate_speed);
	}
	//rotate to the left
	if (key == KEYCODE_LEFT)
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = data->player_view_direction_x;
		data->player_view_direction_x = data->player_view_direction_x * cos(data->rotate_speed) - data->player_view_direction_y * sin(data->rotate_speed);
		data->player_view_direction_y = oldDirX * sin(data->rotate_speed) + data->player_view_direction_y * cos(data->rotate_speed);
		double oldPlaneX = data->camera_plane_x;
		data->camera_plane_x = data->camera_plane_x * cos(data->rotate_speed) - data->camera_plane_y * sin(data->rotate_speed);
		data->camera_plane_y = oldPlaneX * sin(data->rotate_speed) + data->camera_plane_y * cos(data->rotate_speed);
	}
	if (key == KEYCODE_ESC)
		exit(0);
	mlx_clear_window(data->mlx, data->win);
	play(data);
	return (0);
}