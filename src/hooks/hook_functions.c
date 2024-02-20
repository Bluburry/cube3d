#include "cube.h"

void	draw_movements(t_data *data)
{
	draw_lines(data);
	draw_rectangles(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->minimap.img.mlx_img, 0, 0);
}

t_vector	move_forward_backward(t_data *data, int keycode, t_vector new_pos)
{
	if (keycode == W) // W
 	{
 		new_pos.x = data->player.pos.x + -1 * (data->player.dir.x * 0.5 / 5);
 		new_pos.y = data->player.pos.y + -1 * (data->player.dir.y * 0.5 / 5);
 	}
 	else if (keycode == S) // S
 	{
 		new_pos.x = data->player.pos.x + 1 * (data->player.dir.x * 0.5 / 5);
 		new_pos.y = data->player.pos.y + 1 * (data->player.dir.y * 0.5 / 5);
 	}
 	return (new_pos);
}

t_vector	move_left_right(t_data *data, int keycode, t_vector new_pos)
{
	if (keycode == D) // D
 	{
 		new_pos.x = data->player.pos.x - -1 * (data->player.dir.y * 0.5 / 5);
 		new_pos.y = data->player.pos.y + -1 * (data->player.dir.x * 0.5 / 5);
 	}
 	else if (keycode == A) // A
 	{
 		new_pos.x = data->player.pos.x - 1 * (data->player.dir.y * 0.5 / 5);
 		new_pos.y = data->player.pos.y + 1 * (data->player.dir.x * 0.5 / 5);
 	}
 	return (new_pos);
}

void	move(int keycode, t_data *data)
{
	t_vector	new_pos;

	new_pos.x = 0;
	new_pos.y = 0;

	new_pos = move_forward_backward(data, keycode, new_pos);
	new_pos = move_left_right(data, keycode, new_pos);
	if (data->new_map.map[(int)new_pos.y][(int)new_pos.x] != '1')
	{
		data->player.pos.x = new_pos.x;
		data->player.pos.y = new_pos.y;
		draw_movements(data);
	}
}

void	rotate(int keycode, t_data *data)
{
	// double	dist;
 	
 	if (keycode == LEFT) // left arrow
 	{
		data->player.p_ang -= 0.1;
		if (data->player.p_ang < 0)
			data->player.p_ang += 2 * 3.1415926535;
		data->player.dir.x = cos(data->player.p_ang) * 5;
		data->player.dir.y = sin(data->player.p_ang) * 5;
 		draw_movements(data);
 	}
 	else if (keycode == RIGHT) // right arrow
 	{
		data->player.p_ang += 0.1;
		if (data->player.p_ang > (2 * 3.1415926535))
			data->player.p_ang -= 2 * 3.1415926535;
		data->player.dir.x = cos(data->player.p_ang) * 5;
		data->player.dir.y = sin(data->player.p_ang) * 5;
 		draw_movements(data);
 	}
}

int	close_window(int keycode, t_data *data)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
		on_destroy(data);
	else if (keycode == LEFT || keycode == RIGHT)
		rotate(keycode, data);
	else if (keycode == W || keycode == A || keycode == S || keycode == D)
		move(keycode, data);
	return (0);
}

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	mlx_loop_end(data->mlx);
	free(data->mlx);
	exit(0);
}
