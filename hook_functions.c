#include "./libft/libft.h"
#include "map.h"

int	close_window(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
			mlx_destroy_window(data->mlx, data->win);
			mlx_destroy_display(data->mlx);
			free(data->mlx);
			exit(0);
 	}
	return (0);
}

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
