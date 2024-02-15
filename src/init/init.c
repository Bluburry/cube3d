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

void	init_ray(t_raycast *ray)
{
	ray->camera_x = 0;
	ray->cast_vector.x = 0;
	ray->cast_vector.y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist.x = 0;
	ray->sidedist.y = 0;
	ray->deltadist.x = 0;
	ray->deltadist.y = 0;
}

void	init_data(t_data *data)
{
	t_image		img;
	t_minimap	minimap;
	t_vector		*stk;
	t_raycast	raycast;
	t_player	player;

	raycast.cast_vector.x = 0;
	raycast.cast_vector.y = 0;
	raycast.sidedist.x = 0;
	raycast.sidedist.y = 0;
	raycast.deltadist.x = 0;
	raycast.deltadist.y = 0;
	raycast.camera_x = 0;
	raycast.map_x = 0;
	raycast.map_y = 0;
	raycast.step_x = 0;
	raycast.step_y = 0;
	raycast.side = 0;
	
	player.pos.x = 0;
	player.pos.y = 0;
	player.plane.x = 0;
	player.plane.y = 0;
	player.dir.x = 0.0;
	player.dir.y = 0.0;

	data->player = player;

	data->mlx = NULL;
	data->win = NULL;

	img.mlx_img = NULL;
	img.addr = NULL;	

	minimap.map_size = 16;

	stk = NULL;

	data->img = img;
	data->minimap = minimap;
	data->raycast = raycast;
	data->stk = stk;
	data->stk = malloc(sizeof(t_vector) * 720);
}