/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:24:48 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/10 15:31:47 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_strlen_nl(char *line)
{
	int	return_value;

	return_value = 0;
	while (*line && *line != '\n')
	{
		return_value++;
		line++;
	}
	return (return_value);
}

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


void	program_error_end(char *error_message)
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
