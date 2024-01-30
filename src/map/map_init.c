#include "cube.h"

void	init_map(t_data *data)
{
	data->new_map.map = NULL;
	data->new_map.no_path = NULL;
	data->new_map.so_path = NULL;
	data->new_map.we_path = NULL;
	data->new_map.ea_path = NULL;
	data->new_map.floor = 0;	
	data->new_map.sky = 0;
	data->new_map.rows = 0;
	data->new_map.columns = 0;
}

void	set_player_position(t_data *data, int x, int y, int pos)
{
	if (data->pos_y == 0 && data->pos_x == 0)
	{
		data->pos_y = (double)x + 0.5;
		data->pos_x = (double)y + 0.5;
		if (pos == 'E')
			data->dir.x = 1;
		else if (pos == 'W')
			data->dir.x = -1;
		else if (pos == 'S')
			data->dir.y = -1;
		else if (pos == 'N')
			data->dir.y = 1;
		printf("\nDirX: %f | DirY: %f\n", data->dir.x, data->dir.y);	
		return ;
	}
}

void	init_minimap(t_data *data)
{
	int	bpp;
	int	sl;
	int	end;

	data->minimap.width = data->new_map.columns * data->minimap.map_size;
	data->minimap.height = data->new_map.rows * data->minimap.map_size;
	data->minimap.img.mlx_img = mlx_new_image(data->mlx, data->minimap.width,
			data->minimap.height);
	data->minimap.img.addr = (unsigned int *)mlx_get_data_addr(
			data->minimap.img.mlx_img, &bpp, &sl, &end);
}
