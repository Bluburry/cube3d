#include "cube.h"

static void	init_r(t_data *data, t_raycast *r)
{
	if (r->dir.x != 0)
		r->delta.x = fabs(1 / r->dir.x);
	if (r->dir.y != 0)
		r->delta.y = fabs(1 / r->dir.y);
	if (r->dir.x < 0)
	{
		r->step_x = -1;
		r->side.x = (data->player.pos.x - r->map_x) * r->delta.x;
	}
	else
	{
		r->step_x = 1;
		r->side.x = (r->map_x + 1.0 - data->player.pos.x) * r->delta.x;
	}
	if (r->dir.y < 0)
	{
		r->step_y = -1;
		r->side.y = (data->player.pos.y - r->map_y) * r->delta.y;
	}
	else
	{
		r->step_y = 1;
		r->side.y = (r->map_y + 1.0 - data->player.pos.y) * r->delta.y;
	}
	// printf("data->player.pos.x: %f | data->player.pos.y: %f\n\n", data->player.pos.x, data->player.pos.y);
}

static void	dda(t_data *data, t_raycast *r)
{
	while (1)
	{
		if (r->side.x < r->side.y)
		{
			r->side.x += r->delta.x;
			r->map_x += r->step_x;
			r->side_hit = 0;
		}
		else
		{
			r->side.y += r->delta.y;
			r->map_y += r->step_y;
			r->side_hit = 1;
		}
		if (data->new_map.map[r->map_y][r->map_x] == '1')
			break ;
	}
	if (r->side_hit == 0)
		r->wall_dist = (r->side.x - r->delta.x);
	else
		r->wall_dist = (r->side.y - r->delta.y);
	if (r->side_hit == 0 && r->dir.x > 0)
		r->side_hit = 2;
	else if (r->side_hit == 1 && r->dir.y > 0)
		r->side_hit = 3;
}

void	raycast_attempt(t_data *data)
{
	t_raycast	r; //raycast structure

	data->img.mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = (unsigned int *)mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.sl, &data->img.ed);
	data->new_map.no.img = mlx_xpm_file_to_image(data->mlx, "./maps/textures/bricks.xpm", &data->new_map.no.width, &data->new_map.no.height);
	data->new_map.no.addr = (unsigned int *) mlx_get_data_addr(data->new_map.no.img, &data->new_map.no.bpp, &data->new_map.no.sl, &data->new_map.no.ed);
	data->new_map.so.img = mlx_xpm_file_to_image(data->mlx, "./maps/textures/dirt.xpm", &data->new_map.so.width, &data->new_map.so.height);
	data->new_map.so.addr = (unsigned int *) mlx_get_data_addr(data->new_map.so.img, &data->new_map.so.bpp, &data->new_map.so.sl, &data->new_map.so.ed);
	data->new_map.we.img = mlx_xpm_file_to_image(data->mlx, "./maps/textures/coal.xpm", &data->new_map.we.width, &data->new_map.we.height);
	data->new_map.we.addr = (unsigned int *) mlx_get_data_addr(data->new_map.we.img, &data->new_map.we.bpp, &data->new_map.we.sl, &data->new_map.we.ed);
	data->new_map.ea.img = mlx_xpm_file_to_image(data->mlx, "./maps/textures/mud.xpm", &data->new_map.ea.width, &data->new_map.ea.height);
	data->new_map.ea.addr = (unsigned int *) mlx_get_data_addr(data->new_map.ea.img, &data->new_map.ea.bpp, &data->new_map.ea.sl, &data->new_map.ea.ed);
	r.side.x = 0;
	r.side.y = 0;
	r.step_x = 0;
	r.step_y = 0;
	auto int x = -1;
	while (++x <= WIDTH)
	{
		r.camera.x = (2 * x) / (double) WIDTH - 1;
		r.dir.x = data->player.dir.x + data->player.plane.x * r.camera.x;
		r.dir.y = data->player.dir.y + data->player.plane.y * r.camera.x;
		r.map_x = (int) data->player.pos.x;
		r.map_y = (int) data->player.pos.y;
		r.delta.x = MAX;
		r.delta.y = MAX;
		init_r(data, &r);
		dda(data, &r);
		draw_vert(data, &r, x);
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
}
