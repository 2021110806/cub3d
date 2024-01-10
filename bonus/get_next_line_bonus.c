/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:00:26 by minjeon2          #+#    #+#             */
/*   Updated: 2023/12/23 20:25:49 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_invalid_input(int fd, char buf[], char **backup, int *readsize)
{
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (1);
	*readsize = read(fd, buf, BUFFER_SIZE);
	if (*readsize == -1)
	{
		free_ptr(backup, 0, 1);
		return (1);
	}
	if (*readsize == 0 && !(*backup))
		return (1);
	return (0);
}

int	copy_to_return(char **backup, char **return_value, int readsize)
{
	int	idx;

	idx = 0;
	*return_value = malloc (sizeof(char) * ft_gnl_strlen(*backup, 0) \
	+ ft_gnl_strchr(*backup, '\n') + 1);
	if (!(*return_value))
		return ((int) free_ptr(backup, return_value, 2));
	while ((*backup)[idx])
	{
		(*return_value)[idx] = (*backup)[idx];
		if ((*backup)[idx] == '\n')
		{
			(*return_value)[idx++] = '\n';
			break ;
		}
		idx++;
	}
	if (readsize == 0 && (!(**backup) || !(*backup)))
		return ((int) free_ptr(backup, 0, 1));
	(*return_value)[idx] = 0;
	return (1);
}

int	make_new_backup(char **new_backup, char **backup)
{
	int	new_backup_idx;
	int	backup_idx;
	int	backup_len;

	new_backup_idx = 0;
	backup_idx = ft_gnl_strlen(*backup, 0) + 1;
	backup_len = ft_gnl_strlen(*backup, 1);
	while (backup_idx < backup_len)
	{
		(*new_backup)[new_backup_idx] = (*backup)[backup_idx];
		new_backup_idx++;
		backup_idx++;
	}
	(*new_backup)[new_backup_idx] = 0;
	free_ptr(backup, 0, 1);
	*backup = *new_backup;
	if ((**backup) == 0)
		free_ptr(backup, 0, 1);
	return (1);
}

int	join_backup_and_buf(char **backup, char buf[])
{
	char	*backup_saver;

	if (!(*backup) || !(**backup))
		*backup = ft_gnl_strdup("");
	backup_saver = ft_gnl_strjoin(*backup, buf);
	if (!backup_saver)
	{
		free_ptr(backup, 0, 1);
		return (0);
	}
	free_ptr(backup, 0, 1);
	*backup = backup_saver;
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	char		*return_value;
	int			readsize;
	char		*new_backup;

	if (is_invalid_input(fd, buf, &backup, &readsize))
		return ((void *)0);
	while (readsize > 0)
	{	
		buf[readsize] = 0;
		if (!join_backup_and_buf(&backup, buf))
			return ((void *)0);
		if (ft_gnl_strchr(backup, '\n'))
			break ;
		readsize = read(fd, buf, BUFFER_SIZE);
	}
	if (!copy_to_return(&backup, &return_value, readsize))
		return ((void *)0);
	new_backup = malloc ((ft_gnl_strlen(backup, 1) - ft_gnl_strlen(backup, 0)));
	if (!new_backup)
		return (free_ptr(&backup, &return_value, 2));
	if (!make_new_backup(&new_backup, &backup))
		return ((void *)0);
	return (return_value);
}
