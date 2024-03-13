#include "cube.h"

void	clear_matrix(char **mat, int s)
{
	int	i;

	if (s > 0)
	{
		i = -1;
		while (++i < s)
			free(mat[i]);
	}
	else
	{
		i = -1;
		while (mat[++i])
			free(mat[i]);
	}
	free(mat);
}

void	destroy_paths(t_data *data)
{
	if (data->new_map.no.path != NULL)
		free(data->new_map.no.path);
	if (data->new_map.so.path != NULL)
		free(data->new_map.so.path);
	if (data->new_map.we.path != NULL)
		free(data->new_map.we.path);
	if (data->new_map.ea.path != NULL)
		free(data->new_map.ea.path);
	if (data->new_map.map)
	{
		clear_matrix(data->new_map.map, -1);
	}
}

void	destroy_imgs(t_data *data)
{
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx, data->img.mlx_img);
	if (data->new_map.no.img)
		mlx_destroy_image(data->mlx, data->new_map.no.img);
	if (data->new_map.so.img)
		mlx_destroy_image(data->mlx, data->new_map.so.img);
	if (data->new_map.we.img)
		mlx_destroy_image(data->mlx, data->new_map.we.img);
	if (data->new_map.ea.img)
		mlx_destroy_image(data->mlx, data->new_map.ea.img);
}
