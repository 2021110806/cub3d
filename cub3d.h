/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:58:33 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/21 18:34:56 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define TEXTURE_WIDTH 128
# define TEXTURE_HEGIHT 128
# define WEST_PATH "./texture/bird1_128.xpm"
# define EAST_PATH "./texture/bird2_128.xpm"
# define SOUTH_PATH "./texture/bird3_128.xpm"
# define NORTH_PATH "./texture/bird4_128.xpm"
# define GAME_NAME "cub3d"
# define EAST 1
# define WEST 2
# define SOUTH 3
# define NORTH 4
# define FLOOR 5
# define CEILING 6
# define X 0
# define Y 1
# define KEY_PRESS_EVENT 2
# define KEYCODE_UP 13
# define KEYCODE_DOWN 1
# define KEYCODE_LEFT 0
# define KEYCODE_RIGHT 2
# define KEYCODE_ESC 53

# include "./mlx/mlx.h"
# include <stdlib.h>
# include <math.h>

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
} t_double_vector;

typedef struct s_int_coordinate
{
	int	x;
	int	y;
} t_int_coordinate;

typedef struct s_crash_checker
{
	int x;
	int y;
} t_crash_checker;

typedef struct s_data
{
	double				player_position_x;
	double				player_position_y;
	double				player_view_direction_x;
	double				player_view_direction_y;
	double 				camera_plane_x;
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
	t_double_vector curr_measurement_vector;
	t_double_vector delta_vector;
	t_crash_checker crash_checker;
} t_vectors;

typedef struct s_drawing_factors
{
	int draw_start;
	int draw_end;
	int	line_height;
	int	texture_number;
	double wall_crash_spot;
	double curr_drawing_spot;
} t_drawing_factors;

static int	worldMap[24][24] =
						{
							{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
							{4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
							{4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
							{4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
							{4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
							{4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
							{4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
							{4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
							{4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
							{4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
							{4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
							{4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
							{6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
							{8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
							{6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
							{4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
							{4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
							{4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
							{4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
							{4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
							{4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
						};
						
void	init_data(t_data *data);
int	init_buf(t_data *data);
int	*ft_int_malloc(int size);
int **ft_int_pointer_malloc(int size);
void	init_texture(t_data *data);
void draw_image(double vertical_distance, t_int_coordinate *map, t_data *data, t_vectors *vectors, int x);
double	calculate_distance_from_camera_to_wall\
(t_int_coordinate map, t_data *data, t_vectors vectors, t_int_coordinate step);
double	calculate_wall_crash_spot\
(t_data *data, double vertical_distance, t_vectors *vectors);
int	calculate_texture_spot\
(t_data *data, t_vectors *vectors, double wall_crash_spot);
void	draw(t_data *data);
void	draw_floor_and_ceiling(t_data *data);
int	calculate_draw_start(int line_height);
int	calculate_draw_end(int line_height);
int	key_press(int key, t_data *data);

int play(t_data *data);
#endif
