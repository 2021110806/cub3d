/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:22:30 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/04 17:22:31 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_swap(t_sprite *sprite_a, t_sprite *sprite_b)
{
	t_sprite	temp;

	temp.image_number = sprite_a->image_number;
	temp.relative_distance = sprite_a->relative_distance;
	temp.x = sprite_a->x;
	temp.y = sprite_a->y;
	sprite_a->image_number = sprite_b->image_number;
	sprite_a->relative_distance = sprite_b->relative_distance;
	sprite_a->x = sprite_b->x;
	sprite_a->y = sprite_b->y;
	sprite_b->image_number = temp.image_number;
	sprite_b->relative_distance = temp.relative_distance;
	sprite_b->x = temp.x;
	sprite_b->y = temp.y;
}

void	sort_sprite_information(t_data *data)
{
	int	check_index;
	int	maximum_index;
	int	compare_index;

	check_index = 0;
	if (data->args.sprite_count <= 1)
		return ;
	while (check_index < data->args.sprite_count)
	{
		maximum_index = check_index;
		compare_index = check_index + 1;
		while (compare_index < data->args.sprite_count)
		{
			if (data->\
			args.sprite_information[maximum_index].relative_distance < \
			data->\
			args.sprite_information[compare_index].relative_distance)
				maximum_index = compare_index;
			compare_index++;
		}
		sprite_swap(&data->args.sprite_information[check_index], \
		&data->args.sprite_information[maximum_index]);
		check_index++;
	}
}
