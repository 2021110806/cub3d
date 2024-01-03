/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:24:48 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/02 21:24:49 by minkyole         ###   ########.fr       */
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
	while (*color)
	{
		if (!ft_isdigit(*color))
			return (FALSE);
		color++;
	}
	return (TRUE);
}

int	is_in_range(char *color)
{
	if (ft_strlen(color) > 3)
		return (FALSE);
	if (!(0 <= ft_atoi(color) && ft_atoi(color) <= 255))
		return (FALSE);
	return (TRUE);
}

void	progrem_error_end(char *error_message)
{
	write(STDERR_FILENO, error_message, ft_strlen(error_message));
	exit(1);
}

char	*ft_char_malloc(int size)
{
	char	*return_value;

	return_value = malloc (sizeof(char) * size);
	if (!return_value)
		exit(1);
	return (return_value);
}
