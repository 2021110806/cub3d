/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:58:33 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/23 20:08:33 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define TEXTURE_WIDTH 128
# define TEXTURE_HEGIHT 128
# define WEST_PATH "./texture/bird1_128.xpm" // 주황색
# define EAST_PATH "./texture/bird2_128.xpm" // 점박이
# define SOUTH_PATH "./texture/bird3_128.xpm" // 하늘색
# define NORTH_PATH "./texture/bird4_128.xpm" // 코쿠투칸
# define GAME_NAME "cub3d"
# define EAST 0
# define WEST 1
# define SOUTH 2
# define NORTH 3
# define X 0
# define Y 1
# define KEY_PRESS_EVENT 2
# define RED_BUTTON 17
# define KEYCODE_UP 13
# define KEYCODE_DOWN 1
# define KEYCODE_LEFT 0
# define KEYCODE_RIGHT 2
# define KEYCODE_ESC 53
# define FALSE 0
# define TRUE 1
# define MAP_ONE_SPACE_SIZE 10
# define MINIMAP_WALL 1
# define MINIMAP_NULL 32
# define MINIMAP_EMPTY 0
# define MINIMAP_PLAYER 2

# include "./mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include "get_next_line.h"
# include "./libft/libft.h"
typedef struct s_image_info
{
	void	*image;
	int		*texture;
	int		size;
	int		bit_per_pixel;
	int		endian;
	int		width;
	int		height;
}	t_image_info;

typedef struct s_double_vector
{
	double	x;
	double	y;
}	t_double_vector;

typedef struct s_int_coordinate
{
	int	x;
	int	y;
}	t_int_coordinate;

typedef struct s_crash_checker
{
	int	x;
	int	y;
}	t_crash_checker;

typedef struct s_rgb_color
{
	int r;
	int g;
	int b;
}	t_rgb_color;

typedef struct s_data
{
	double				player_position_x;
	double				player_position_y;
	double				player_view_direction_x;
	double				player_view_direction_y;
	double				camera_plane_x;
	double				camera_plane_y;
	void				*mlx;
	void				*win;
	t_image_info		img;
	int					buf[WIN_HEIGHT][WIN_WIDTH];
	int					**texture;
	int					last_hit_pos;
	double				move_speed;
	double				rotate_speed;
	double				curr_ratio;
}	t_data;

typedef struct s_vectors
{
	t_double_vector	ray_vector;
	t_double_vector	curr_measurement_vector;
	t_double_vector	delta_vector;
	t_crash_checker	crash_checker;
}	t_vectors;

typedef struct s_drawing_factors
{
	int		draw_start;
	int		draw_end;
	int		line_height;
	int		texture_number;
	double	wall_crash_spot;
	double	curr_drawing_spot;
	double	vertical_distance;
	double	delta;
	int		x;
}	t_drawing_factors;

static int	worldMap[24][24] =
						{
							{1,1,1,1,1,1,1},
							{1,0,0,0,0,0,1},
							{1,0,0,0,1,0,1},
							{1,0,0,0,1,0,1},
							{1,0,0,0,1,0,1},
							{1,0,0,0,1,0,1},
							{1,1,1,1,1,1,1},
						};
						
void	init_data(t_data *data);
int		init_buf(t_data *data);
int		*ft_int_malloc(int size);
int		**ft_int_pointer_malloc(int size);
void	init_texture(t_data *data);
void	draw_image(t_drawing_factors *drawing_factors, \
t_data	*data, t_vectors *vectors);
double	calculate_distance_from_camera_to_wall(t_int_coordinate map, \
t_data *data, t_vectors vectors, t_int_coordinate step);
double	calculate_wall_crash_spot(t_data *data, \
double vertical_distance, t_vectors *vectors);
int		calculate_texture_spot(t_data *data, \
t_vectors *vectors, double wall_crash_spot);
void	draw_buf(t_data *data);
void	draw_floor_and_ceiling(t_data *data);
int		calculate_draw_start(int line_height);
int		calculate_draw_end(int line_height);
int		key_press(int key, t_data *data);
int		play(t_data *data);
double	calculate_distance_from_camera_to_wall(t_int_coordinate map, \
t_data *data, t_vectors vectors, t_int_coordinate step);
void	move_ray(t_vectors *vectors, \
t_int_coordinate *map, t_data *data, t_int_coordinate step);
void	set_x_vector(t_int_coordinate *map, t_data \
*data, t_int_coordinate *step, t_vectors *vectors);
void	set_y_vector(t_int_coordinate *map, t_data \
*data, t_int_coordinate *step, t_vectors *vectors);
void	set_curr_measurement_vector(t_int_coordinate *map, t_data \
*data, t_int_coordinate *step, t_vectors *vectors);
void	set_vector(t_data *data, t_vectors *vectors, t_int_coordinate *map);
void	set_texture(t_data *data, char *direction, int index);
void	set_player(t_data *data);
void	set_textures(t_data *data);
int		draw_wall(t_data *data);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
int		progrem_end(void);
void	set_player_direction(t_data *data, char direction);
void	draw_minimap(t_data *data);
int 	rgb_convert_int(t_rgb_color color);
void	set_rgb_color(t_rgb_color *color, int r, int g, int b);
int		check_minimap_current_location (int y, int x, t_data *data);
#endif
