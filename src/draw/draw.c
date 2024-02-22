#include "cube.h"

void	draw_rectangle(t_data *data, int x, int y, long color)
{
	int	i;
	int	j;

	x *= data->minimap.map_size;
	y *= data->minimap.map_size;
	i = 0;
	while (i < data->minimap.map_size)
	{
		j = 0;
		while (j < data->minimap.map_size)
		{
			data->minimap.img.addr[(y + i) * data->new_map.columns
				* data->minimap.map_size + x + j] = color;
			j++;
		}
		i++;
	}
}

void	draw_rectangles(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->new_map.rows)
	{
		j = 0;
		while (data->new_map.map[i][j])
		{
			if (data->new_map.map[i][j] == '1')
				draw_rectangle(data, j, i, 0x00FFFFFF);
			else
				draw_rectangle(data, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}

void	draw_line(t_data *data, t_vector pos1, t_vector pos2, long color)
{
	double	delta_x;
	double	delta_y;
	double	step;
	int		coord;

	delta_x = pos2.x - pos1.x;
	delta_y = pos2.y - pos1.y;
	step = fabs(delta_y);
	if (fabs(delta_x) > fabs(delta_y))
		step = fabs(delta_x);
	delta_x /= step;
	delta_y /= step;
	while (fabs(pos2.x - pos1.x) > fabs(delta_x)
		|| fabs(pos2.y - pos1.y) > fabs(delta_y))
	{
		coord = floor(pos1.y) * floor(data->minimap.width) + floor(pos1.x);
		data->minimap.img.addr[coord] = color;
		pos1.x += delta_x;
		pos1.y += delta_y;
	}
}

void	draw_lines(t_data *data)
{
	t_vector	pos1;
	t_vector	pos2;
	int		i;

	i = -1;
	pos1.y = 0;
	pos2.y = data->minimap.height;
	while (++i < data->new_map.columns)
	{
		pos1.x = i * data->minimap.map_size;
		pos2.x = i * data->minimap.map_size;
		draw_line(data, pos1, pos2, 0x3B3B3B);
	}
	i = -1;
	pos1.x = 0;
	pos2.x = data->minimap.width;
	while (++i < data->new_map.rows)
	{
		pos1.y = i * data->minimap.map_size;
		pos2.y = i * data->minimap.map_size;
		draw_line(data, pos1, pos2, 0x3B3B3B);
	}
}

void	draw_player(t_data *data)
{
	t_vector	mini_pos;
	t_vector	dir;

	mini_pos.x = (ceil(data->player.pos.x) * data->minimap.map_size)
		- (data->minimap.map_size / 2);
	mini_pos.y = (ceil(data->player.pos.y) * data->minimap.map_size)
		- (data->minimap.map_size / 2);

	// printf("pos.x: %f pos.y: %f\n", pos.x, pos.y);
	// printf("data->dir.x: %f data->dir.y: %f\n", data->dir.x, data->dir.y);	
	// printf("X: %f - Y: %f  - Cam: %f\n", data->raycast.dir.x, data->raycast.dir.y, cam_x);
	while (i < WIDTH)
	{
		data->raycast.dir.x = data->dir.x;
		data->raycast.dir.y = data->dir.y;
		// printf("raycast.dir.x: %f raycast.dir.y: %f - Cam: %f\n", data->raycast.dir.x, data->raycast.dir.y, cam_x);
		draw_line(data, pos, data->raycast.dir, 0x0000FF0);
		i++;
	}
	// dir.x = mini_pos.x + data->player.dir.x * 25;
	// dir.y = mini_pos.y + data->player.dir.y * 25;
	// draw_line(data, mini_pos, dir, 0x0000FF0);
	draw_rectangle(data, (int)data->player.pos.x, (int)data->player.pos.y, 0x00FF0000);
}

	// printf("\n-Minimap-\nPlayer Pos x: %f Player Pos y: %f\n", data->player.pos.x, data->player.pos.y);
	// printf("Player Dir x: %f Player Dir y: %f\n\n", data->player.dir.x, data->player.dir.y);	
	// printf("Pos x: %f Pos y: %f\n", pos.x, pos.y);
	// printf("Dir x: %f Dir y: %f\n", dir.x, dir.y);
	// printf("Angulo: %f\n\n", data->player.p_ang);
		