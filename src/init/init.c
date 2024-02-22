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
	if (data->player.pos.y == 0 && data->player.pos.x == 0)
	{
		data->player.pos.y = (double)x + 0.5;
		data->player.pos.x = (double)y + 0.5;
		if (pos == 'E')
		{
			data->player.p_ang = 0;
			data->player.dir.x = 1;
			data->player.dir.y = 0;
			data->player.plane.x = 0;
			data->player.plane.y = 0.66;
		}
		else if (pos == 'W')
		{
			data->player.p_ang = PI;
			data->player.dir.x = -1;
			data->player.dir.y = 0;
			data->player.plane.x = 0;
			data->player.plane.y = -0.66;
		}
		else if (pos == 'S')
		{
			data->player.p_ang = PI * 3 / 2;
			data->player.dir.x = 0.0f;
			data->player.dir.y = 1.0f;
			data->player.plane.x = -0.66;
			data->player.plane.y = 0;
		}
		else if (pos == 'N')
		{
			data->player.p_ang = PI / 2;
			data->player.dir.x = 0.0f;
			data->player.dir.y = -1.0f;
			data->player.plane.x = 0.66;
			data->player.plane.y = 0;
		}
		return ;
	}
}

void	init_data(t_data *data)
{
	t_image		img;
	t_minimap	minimap;
	t_raycast	raycast;
	t_player	player;

	img.mlx_img = NULL;
	img.addr = NULL;	

	minimap.map_size = 16;

	raycast.dir.x = 0;
	raycast.dir.y = 0;
	
	player.pos.x = 0;
	player.pos.y = 0;
	player.plane.x = 0;
	player.plane.y = 0;

	player.p_ang = 0;
	player.dir.x = 0;
	player.dir.y = 0;

	data->mlx = NULL;
	data->win = NULL;
	data->img = img;
	data->minimap = minimap;
	data->raycast = raycast;
	data->player = player;
}
// ## Bonus ##
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
	
	// draw_lines(data);
	// draw_rectangles(data);
	// draw_player(data);
}