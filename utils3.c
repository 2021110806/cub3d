/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:10:45 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/03 12:10:46 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprite    *ft_sprite_malloc(int size)
{
	t_sprite	*return_value;

	return_value = malloc (sizeof(t_sprite) * size);
	if (!return_value)
		exit(-1);
	return (return_value);
}
