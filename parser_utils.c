/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 19:31:02 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/28 19:36:20 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_whitespace(char charactor)
{
	if (charactor == ' ' || charactor == '\t' || charactor == '\n' || \
	charactor == 'v' || charactor == '\r')
		return (TRUE);
	return (FALSE);
}

int	only_whitespace(char *line)
{
	while (*line)
	{
		if (is_whitespace(*line))
			line++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	count_line(int fd, char *file_name)
{
	int		count;
	char	*line;

	count = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		count++;
	}
	return (count + 1);
}

char	**ft_char_two_pointer_malloc(int size)
{
	char	**return_value;

	return_value = malloc(sizeof (char *) * size);
	if (!return_value)
		exit(1);
	return (return_value);
}

char	**ft_realloc(t_args *args)
{
	int		i;
	char	**return_value;

	i = 0;
	return_value = ft_char_two_pointer_malloc(args -> map.size * 2);
	while (i < args -> map.size)
	{
		return_value[i] = args -> map.map[i];
		i++;
	}
	args -> map.map = return_value;
	args -> map.size *= 2;
	return (return_value);
}
