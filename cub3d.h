/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:58:33 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/18 19:56:25 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define TEXTURE_WIDTH 64
# define TEXTURE_HEGIHT 64
# define WEST_PATH "./texture/wood.xpm"
# define EAST_PATH "./texture/wood.xpm"
# define SOUTH_PATH "./texture/wood.xpm"
# define NORTH_PATH "./texture/wood.xpm"
# define GAME_NAME "cub3d"
# define EAST 1
# define WEST 2
# define SOUTH 3
# define NORTH 4
# define FLOOR 5
# define CEILING 6
# define X 0
# define Y 1

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
}	t_data;

typedef struct s_vectors
{
	t_double_vector	ray_vector;
	t_double_vector curr_measurement_vector;
	t_double_vector delta_vector;
	t_crash_checker crash_checker;
} t_vectors;

void	init_data(t_data *data);
int	init_buf(t_data *data);
int	*ft_int_malloc(int size);
int **ft_int_pointer_malloc(int size);
void	init_texture(t_data *data);
#endif
