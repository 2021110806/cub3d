/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:58:33 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/02 18:07:08 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define TEXTURE_WIDTH 128
# define TEXTURE_HEGIHT 128
# define GAME_NAME "cub3d"
# define EAST 0
# define WEST 1
# define SOUTH 2
# define NORTH 3
# define CLOSE_DOOR 4
# define OPENED_DOOR 5
# define CEILING 6
# define FLOOR 7
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
# define MINIMAP_WALL 49
# define MINIMAP_NULL 53
# define MINIMAP_EMPTY 48
# define MINIMAP_PLAYER 2
# define MINIMAP_CLOSE_DOOR 50
# define MINIMAP_OPEN_DOOR 51
# define MINIMAP_CHICKADEE 52
# define MOUSE_LEFT_CLICK 1
# define MOUSE_RIGHT_CLICK 2
# define CLOSE_DOOR_IMAGE_PATH "./texture/close_door.xpm"
# define OPENED_DOOR_IMAGE_PATH "./texture/opened_door.xpm"
# define ARGUMENT_ERROR "ERROR : invalid argument\n"
# define FILE_ERROR "ERROR : invalid file format\n"
# define COLOR_FORMAT_ERROR "ERROR : invalid color setting\n"
# define TEXTURE_ERROR "ERROR : texture not setting\n"
# define COLOR_ERROR "ERROR : color not settting\n"
# define SETTING_FORMAT_ERROR "ERROR : inavalid setting format\n"
# define USER_POSITION_ERROR "ERROR : invalid user position\n"
# define MAP_ERROR "ERROR : inavalid map\n"
# include "./mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
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
	int	r;
	int	g;
	int	b;
}	t_rgb_color;

typedef struct s_minimap_color
{
	t_rgb_color	empty_color;
	t_rgb_color	player_color;
	t_rgb_color	wall_color;
	t_rgb_color	null_color;
	t_rgb_color	door_close_color;
	t_rgb_color	door_open_color;
}	t_minimap_color;

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

typedef struct s_map
{
	char	**map;
	int		size;
}	t_map;

typedef struct s_args
{
	int				y_max;
	int				x_max;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	t_rgb_color		floor_color;
	t_rgb_color		ceiling_color;
	t_map			map;
}	t_args;

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
	int					is_mouse_move_active;
	t_args				args;
}	t_data;

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
void	move_left(t_data *data, double rotate_speed);
void	move_right(t_data *data, double rotate_speed);
int		progrem_end(void);
void	set_player_direction(t_data *data, char direction);
void	draw_minimap(t_data *data);
int		rgb_convert_int(t_rgb_color color);
void	set_rgb_color(t_rgb_color *color, int r, int g, int b);
char	check_minimap_current_location(int y, int x, t_data *data);
void	parse_argv(t_args *args, int argc, char **argv);
int		is_correct_map_line(char *line);
char	**ft_realloc(t_args *args);
char	**ft_char_two_pointer_malloc(int size);
int		count_line(int fd, char *file_name);
int		only_whitespace(char *line);
int		is_whitespace(char charactor);
void	check_mouse_rotate(t_data *data);
void	is_not_set_ceiling_or_floor_color(t_args *args);
void	is_no_texture(t_args *args);
void	is_wrapped_by_wall(t_args *args);
int		mouse_press(int buttom, int x, int y, t_data *data);
int		double_range_check(double value, double center, double range);
void	is_correct_user_position(t_args *args);
void	is_next_line_is_map(int fd, char **line);
int		check_direction(char *path);
int		make_color(char **line);
void	pass_white_space(char **line);
void	copy_path(int direction, char *line, t_args *args, int i);
void	set_direction(char *line, t_args *args);
void	pass_white_space(char **line);
void	copy_path(int direction, char *line, t_args *args, int i);
int		make_color(char **line);
void	set_direction(char *line, t_args *args);
void	init_minimap_color(t_minimap_color *minimap_color);
void	draw_minimapa_space(int current_location, \
t_int_coordinate minimap_coordinate, t_data *data, \
t_minimap_color minimap_color);
void	draw_map_one_space(int draw_start_y, int draw_start_x, \
t_data *data, t_rgb_color color);
void	set_direction_east_path(char *line, t_args *args);
void	set_direction_west_path(char *line, t_args *args);
void	set_direction_south_path(char *line, t_args *args);
void	set_direction_north_path(char *line, t_args *args);
int		is_space_in_contact_with_wall(t_args *args);
int		arr_size_len(char **arr);
int		is_all_digit(char *color);
int		is_in_range(char *color);
void	progrem_error_end(char *error_message);
char	*set_all_direction(int fd, t_args *args);
void	check_parameter(int argc);
void	check_cub_file(char **argv);
void	set_map(int fd, t_args *args, char *line);
int		check_direction(char *path);
char	*ft_char_malloc(int size);
void	make_map_rectangular(t_args *args);
void	make_space_to_integer(t_args *args);
int		is_map_edge_check(t_args *args);
#endif
