/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:58:33 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/16 21:25:13 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./mlx/mlx.h"
# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define TEX_WIDTH 64
# define TEX_HEGIHT 64
# define WEST_PATH "texture/wood"
# define EAST_PATH "texutre/wood"
# define SOUTH_PATH "texture/wood"
# define NORTH_PATH "texture/wood"
# define EAST 1
# define WEST 2
# define SOUTH 3
# define NORTH 4
# define FLOOR 5
# define CEILING 6
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

typedef struct s_data
{
	double				player_position_X;
	double				player_position_Y;
	double				player_view_X;
	double				player_view_Y;
	double 				camera_X;
	double				camera_Y;
	void				*mlx;
	void				*win;
	t_image_info			*img;
	int					buf[WIN_HEIGHT][WIN_WIDTH];
	int					**texture;
}	t_data;

#endif
