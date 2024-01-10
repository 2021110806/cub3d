/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:24:48 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/10 16:17:47 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_strlen_nl(char *line)
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
