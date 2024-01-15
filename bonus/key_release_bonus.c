/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyole <minkyole@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:35:43 by minkyole          #+#    #+#             */
/*   Updated: 2024/01/15 15:35:44 by minkyole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	key_release(int key, t_data *data)
{
	data->current_input_key = KEYCODE_NOT_INPUT;
	(void) key;
	(void) data;
	return (0);
}
