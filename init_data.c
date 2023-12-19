#include "cub3d.h"

int	init_buf(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < WIN_HEIGHT)
	{
		while (j < WIN_WIDTH)
		{
			data -> buf[i][j] = 0;
			j++;
		}
		i++;
	}
	return (1);
}

void	init_data(t_data *data)
{
	data = malloc(sizeof (data));
	if (!data)
		exit(-1);
}
