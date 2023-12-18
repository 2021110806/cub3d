#include "cub3d.h"

int	*ft_int_malloc(int size)
{
	int	*return_value;

	return_value = malloc (sizeof(int) * size);
	if (!return_value)
		exit(-1);
	return (return_value);
}

int **ft_int_pointer_malloc(int size)
{
	int	**return_value;

	return_value = malloc (sizeof(int *) * size);
	if (!return_value)
		exit(-1);
	return (return_value);
}

void	init_texture(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < TEXTURE_HEGIHT)
	{
		j = 0;
		while (j < TEXTURE_WIDTH)
			data -> texture[i][j++] = 0;
		i++;
	}
}
