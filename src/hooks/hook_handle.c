#include "cube.h"

int	on_destroy(t_data *data)
{
	destroy_paths(data);
	destroy_imgs(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		mlx_loop_end(data->mlx);
		free(data->mlx);
	}
	exit(0);
}

int	user_input(int keycode, t_data *data)
{
	mlx_mouse_hide(data->mlx, data->win);
	mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
	if (keycode == ESC)
		on_destroy(data);
	else if (keycode == LEFT || keycode == RIGHT)
		rotate(keycode, 0.1, data);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		move(keycode, data);
	else if (keycode == ALT || keycode == TAB)
		mlx_mouse_show(data->mlx, data->win);
	return (0);
}

int	mouse_input(int x, int y, t_data *data)
{
	mlx_mouse_get_pos(data->mlx, data->win, &x, &y);
	x -= WIDTH / 2;
	if (x < 0)
		rotate(LEFT, 0.013, data);
	else if (x != 0)
		rotate(RIGHT, 0.013, data);
	if (x != 0)
		mlx_mouse_move(data->mlx, data->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
