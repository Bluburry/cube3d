#include "cube.h"

void	draw_movements(t_data *data)
{
	draw_lines(data);
	draw_rectangles(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->minimap.img.mlx_img, 0, 0);
}

t_vector	forward_backward(t_data *data, int keycode, t_vector new_pos)
{
	if (keycode == MOVE_UP)
	{
		new_pos.x = data->player.pos.x + -1 * (data->dir.x * 0.5 / 5);
		new_pos.y = data->player.pos.y + -1 * (data->dir.y * 0.5 / 5);
	}
	else if (keycode == MOVE_DOWN)
	{
		new_pos.x = data->player.pos.x + 1 * (data->dir.x * 0.5 / 5);
		new_pos.y = data->player.pos.y + 1 * (data->dir.y * 0.5 / 5);
	}
	return (new_pos);
}

t_vector	left_right(t_data *data, int keycode, t_vector new_pos)
{
	if (keycode == MOVE_RIGHT)
	{
		new_pos.x = data->player.pos.x - -1 * (data->dir.y * 0.5 / 5);
		new_pos.y = data->player.pos.y + -1 * (data->dir.x * 0.5 / 5);
	}
	else if (keycode == MOVE_LEFT)
	{
		new_pos.x = data->player.pos.x - 1 * (data->dir.y * 0.5 / 5);
		new_pos.y = data->player.pos.y + 1 * (data->dir.x * 0.5 / 5);
	}
	return (new_pos);
}

void	movements(int keycode, t_data *data)
{
	t_vector	new_pos;

	new_pos.x = 0;
	new_pos.y = 0;

	new_pos = forward_backward(data, keycode, new_pos);
	new_pos = left_right(data, keycode, new_pos);
	if (data->new_map.map[(int)new_pos.y][(int)new_pos.x] != '1')
	{
		data->player.pos.x = new_pos.x;
		data->player.pos.y = new_pos.y;
		draw_movements(data);
	}
}

void	rotate(int keycode, t_data *data)
{
	double	dist;

 	if (keycode == ROTATE_LEFT)
 	{
		data->dir.x = data->dir.x * cos(1 * 0.05) - data->dir.y * sin(1 * 0.05);
		data->dir.y = data->dir.y * cos(1 * 0.05) + data->dir.x * sin(1 * 0.05);
		dist = hypot(data->dir.x, data->dir.y);
		data->dir.x /= dist;
		data->dir.y /= dist;
 		draw_movements(data);
 	}
 	else if (keycode == ROTATE_RIGHT)
 	{
		data->dir.x = data->dir.x * cos(-1 * 0.05) - data->dir.y * sin(-1 * 0.05);
		data->dir.y = data->dir.y * cos(-1 * 0.05) + data->dir.x * sin(-1 * 0.05);
		dist = hypot(data->dir.x, data->dir.y);
		data->dir.x /= dist;
		data->dir.y /= dist;
 		draw_movements(data);
		// printf("IN -- Dir_x: %f | Dir_y: %f, \n", data->dir.x, data->dir.y);
 	}
}

int	close_window(int keycode, t_data *data)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
 	}
 	else if (keycode == 65361 || keycode == 65363)
 		rotate(keycode, data);
 	else
 		movements(keycode, data);
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