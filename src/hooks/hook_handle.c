#include "cube.h"

static void	destroy_imgs(t_data *data)
{
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->new_map.no.img)
		mlx_destroy_image(data->mlx, data->new_map.no.img);
	if (data->new_map.so.img)
		mlx_destroy_image(data->mlx, data->new_map.so.img);
	if (data->new_map.we.img)
		mlx_destroy_image(data->mlx, data->new_map.we.img);
	if (data->new_map.ea.img)
		mlx_destroy_image(data->mlx, data->new_map.ea.img);

}

void	on_destroy(t_data *data)hook_start
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	destroy_imgs(data);
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
