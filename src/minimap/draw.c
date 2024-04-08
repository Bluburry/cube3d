#include "cube.h"

static void	draw_rectangle(t_data *data, int x, int y, long color)
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
			data->minimap.img.addr[(y + i) * 33
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

void	draw_player(t_data *data)
{
	draw_rectangle(data, (int)data->player.pos.x, (int)data->player.pos.y, 0x00FF0000);
}

void	draw_movements(t_data *data)
{
	draw_rectangles(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->minimap.img.mlx_img, 0, 0);
}