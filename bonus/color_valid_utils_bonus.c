/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_valid_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:32:44 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/10 15:34:54 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	arr_size_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	is_all_digit(char *color)
{
	while (*color && (*color) != '\n')
	{
		if (!ft_isdigit(*color))
			return (FALSE);
		color++;
	}
	return (TRUE);
}

int	is_in_range(char *color)
{
	if (ft_strlen_nl(color) > 3)
		return (FALSE);
	if (!(0 <= ft_atoi(color) && ft_atoi(color) <= 255))
		return (FALSE);
	return (TRUE);
}
