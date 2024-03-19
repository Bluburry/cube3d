#include "cube.h"

void	set_north_south_direction(t_player *player, int	pos)
{
	if (pos == 'S')
	{
		player->p_ang = PI * 3 / 2;
		player->dir.x = 0.0f;
		player->dir.y = 1.0f;
		player->plane.x = -0.66;
		player->plane.y = 0;
	}
	else if (pos == 'N')
	{
		player->p_ang = PI / 2;
		player->dir.x = 0.0f;
		player->dir.y = -1.0f;
		player->plane.x = 0.66;
		player->plane.y = 0;
	}
}

void	set_west_east_direction(t_player *player, int pos)
{
	if (pos == 'E')
	{
		player->p_ang = PI;
		player->dir.x = 1.0f;
		player->dir.y = 0.0f;
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
	else if (pos == 'W')
	{
		player->p_ang = 0;
		player->dir.x = -1.0f;
		player->dir.y = 0.0f;
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
}

void	set_player_position(t_data *data, int x, int y, int pos)
{
	data->player.pos.y = (double)x + 0.5;
	data->player.pos.x = (double)y + 0.5;

	set_north_south_direction(&data->player, pos);
	set_west_east_direction(&data->player, pos);
}

void	init_map(t_data *data)
{
	data->new_map.map = NULL;
	data->new_map.no.img = NULL;
	data->new_map.so.img = NULL;
	data->new_map.we.img = NULL;
	data->new_map.ea.img = NULL;
	data->new_map.no.addr = NULL;
	data->new_map.so.addr = NULL;
	data->new_map.we.addr = NULL;
	data->new_map.ea.addr = NULL;
	data->new_map.no.path = NULL;
	data->new_map.so.path = NULL;
	data->new_map.we.path = NULL;
	data->new_map.ea.path = NULL;
	data->new_map.floor = 0;
	data->new_map.sky = 0;
	data->new_map.rows = 0;
	data->new_map.columns = 0;
}

void	init_data(t_data *data)
{
	t_image		img;
	t_player	player;

	img.mlx_img = NULL;
	img.addr = NULL;	
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
	data->player = player;
	init_map(data);
}
