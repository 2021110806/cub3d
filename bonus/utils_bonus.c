/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:03:22 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/10 16:17:43 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	*ft_int_malloc(int size)
{
	int	*return_value;

	return_value = malloc (sizeof(int) * size);
	if (!return_value)
		exit(-1);
	return (return_value);
}

int	**ft_int_pointer_malloc(int size)
{
	int	**return_value;

	return_value = malloc (sizeof(int *) * size);
	if (!return_value)
		exit(-1);
	return (return_value);
}

void	init_texture(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < TEXTURE_HEGIHT)
	{
		j = 0;
		while (j < TEXTURE_WIDTH)
			data -> texture[i][j++] = 0;
		i++;
	}
}

int	program_end(void)
{
	exit (0);
}

int	double_range_check(double value, double center, double range)
{
	return ((value >= (center - range)) && (value <= (center + range)));
}
