/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:35:02 by minjeon2          #+#    #+#             */
/*   Updated: 2024/01/10 14:33:03 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*return_value;
	int		i;

	i = 0;
	while (s[i])
		i++;
	return_value = (char *)s;
	while (i > 0)
	{
		if (return_value[i] == (char)c)
			return (&return_value[i]);
		i--;
	}
	if (return_value[i] == (char)c)
		return (&return_value[i]);
	return ((void *)0);
}
