#include "cube.h"

void	draw_movements(t_data *data)
{
	// draw_lines(data);
	draw_rectangles(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->minimap.img.mlx_img, 0, 0);
}

t_vector	move_forward_backward(t_data *data, int keycode, t_vector new_pos)
{
	if (keycode == W) // W
 	{
 		new_pos.x = data->player.pos.x + (data->player.dir.x) * 0.2;
 		new_pos.y = data->player.pos.y + (data->player.dir.y) * 0.2;
 	}
 	else if (keycode == S) // S
 	{
 		new_pos.x = data->player.pos.x - (data->player.dir.x * 0.2);
 		new_pos.y = data->player.pos.y - (data->player.dir.y * 0.2);
 	}
 	return (new_pos);
}

t_vector	move_left_right(t_data *data, int keycode, t_vector new_pos)
{
	// auto double	ang = data->player.p_ang;

	if (keycode == D) // D
 	{
 		new_pos.x = data->player.pos.x - data->player.dir.y * 0.2;
		new_pos.y = data->player.pos.y + data->player.dir.x * 0.2;
 		// ang -= PI / 2;
 		// new_pos.x = data->player.pos.x + (cos(ang));
 		// new_pos.y = data->player.pos.y + (sin(ang));
 		// printf("Cos Ang: %f | Sin Ang: %f\n", cos(ang), sin(ang));
 		// printf("Ang: %f | NewPos_X: %f | NewPos_Y: %f\n", ang, new_pos.x, new_pos.y);
 	}
 	else if (keycode == A) // A
 	{
 		new_pos.x = data->player.pos.x + data->player.dir.y * 0.2;
		new_pos.y = data->player.pos.y - data->player.dir.x * 0.2;
 		// ang += PI / 2;
 		// new_pos.x = data->player.pos.x + (cos(ang));
 		// new_pos.y = data->player.pos.y + (sin(ang));
 		// printf("Cos Ang: %f | Sin Ang: %f\n\n", cos(ang), sin(ang));
 		// printf("Ang: %f | NewPos_X: %f | NewPos_Y: %f\n\n", ang, new_pos.x, new_pos.y);
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
	 		// printf("data->player.pos.x: %f | data->player.pos.y: %f\n\n", data->player.pos.x, data->player.pos.y);
 		raycast_attempt(data);
		// draw_movements(data);
	}
}

void	rotate(int keycode, t_data *data)
{
	auto double olddir_x = data->player.dir.x, rot = 0.3, oldplane_x = data->player.plane.x;
 	
 	if (keycode == LEFT)
 		rot *= -1;	
	data->player.p_ang += rot; 	
 	data->player.dir.x = data->player.dir.x * cos(rot) - data->player.dir.y * sin(rot);
 	data->player.dir.y = olddir_x * sin(rot) + data->player.dir.y * cos(rot);
 	data->player.plane.x = data->player.plane.x * cos(rot) - data->player.plane.y * sin(rot); 
 	data->player.plane.y = oldplane_x * sin(rot) + data->player.plane.y * cos(rot); 
 	raycast_attempt(data);
 	// draw_movements(data);
}

int	close_window(int keycode, t_data *data)
{
	// printf("KEYCODE: %d\n", keycode);
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
