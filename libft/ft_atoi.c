/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:55:07 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/10 17:35:20 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	return_value;

	i = 0;
	minus = 1;
	return_value = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (-1);
	while ('0' <= str[i] && str[i] <= '9')
	{
		return_value = return_value * 10 + minus * (str[i] - 48);
		i++;
	}
	return (return_value);
}
