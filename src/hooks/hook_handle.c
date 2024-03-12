#include "cube.h"

int	on_destroy(t_data *data)
{
	destroy_paths(data);
	destroy_imgs(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	mlx_loop_end(data->mlx);
	free(data->mlx);
	exit(0);
}

int	user_input(int keycode, t_data *data)
{
	if (keycode == ESC)
		on_destroy(data);
	else if (keycode == LEFT || keycode == RIGHT)
		rotate(keycode, data);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		move(keycode, data);
	return (0);
}
