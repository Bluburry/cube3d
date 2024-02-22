#include "cube.h"

void	init_r(t_data *data, t_raycast *r)
{
	r->dir.x = data->player.dir.x + data->player.plane.x * r->camera.x;
	r->dir.y = data->player.dir.y + data->player.plane.y * r->camera.x;
	r->map_x = (int) data->player.pos.x;
	r->map_y = (int) data->player.pos.y;
	r->delta.x = MAX;
	r->delta.y = MAX;
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
}

void	dda(t_data *data, t_raycast *r)
{
	auto int side_hit = 0;
	while (1)
	{
		if (r->side.x < r->side.y)
		{
			r->side.x += r->delta.x;
			r->map_x += r->step_x;
			side_hit = 0;
		}
		else
		{
			r->side.y += r->delta.y;
			r->map_y += r->step_y;
			side_hit = 1;
		}
		if (data->new_map.map[r->map_y][r->map_x] == '1')
			break ;
	}
	//printf("side_hit: %d, ray hit coordinates: %d, %d\n", side_hit, r->map_y, r->map_x);
	if (side_hit == 0)
		r->wall_dist = (r->side.x - r->delta.x);
	else
		r->wall_dist = (r->side.y - r->delta.y);
}

#define WALL_CLR 0x0000FF00
#define REST_CLR 0x00000000

void	draw_vert(t_data *data, int x, double dist)
{
	//unsigned int	*pxl;

	auto int line_height = (int)(HEIGHT / dist);
	auto int draw_start = -line_height / 2 + HEIGHT / 2;
	auto int draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	//printf("dist: %f\nline_height: %d\ndraw start: %d\ndraw end: %d\n", dist, line_height, draw_start, draw_end);
	auto int y = -1;
	while (++y < draw_start)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, REST_CLR);
		//pxl = data->img.addr + (x * data->img.sl + x * (data->img.bpp / 8));
		//*pxl = (unsigned int) REST_CLR;
	}
	while (y++ < draw_end)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, WALL_CLR);
		//pxl = data->img.addr + (x * data->img.sl + y * (data->img.bpp / 8));
		//*pxl = (unsigned int) WALL_CLR;
	}
	while (y++ < HEIGHT)
	{
		mlx_pixel_put(data->mlx, data->win, x, y, REST_CLR);
		//pxl = data->img.addr + (x * data->img.sl + y * (data->img.bpp / 8));
		//*pxl = (unsigned int) REST_CLR;
	}
}

void	raycast_attempt(t_data *data)
{
	t_raycast	r; //raycast structure

	/* printf("player info:\npos x: %f, y: %f\ndir x: %f, y: %f\nplane x: %f, y: %f\n\n", \
		data->player.pos.x, data->player.pos.y, \
		data->player.dir.x, data->player.dir.y, \
		data->player.plane.x, data->player.plane.y); */
	data->img.mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = (unsigned int *)mlx_get_data_addr(data->img.mlx_img, \
		&data->img.bpp, &data->img.sl, &data->img.ed);
	auto int x = -1;
	while (++x < WIDTH)
	{
		r.camera.x = (2 * x) / (double) WIDTH - 1;
		r.side.x = 0;
		r.side.y = 0;
		r.step_x = 0;
		r.step_y = 0;
		init_r(data, &r);
		/* printf("Raycast details for %d:\nr.camera.x: %f, r.camera.y: %f\n", x, r.camera.x,r.camera.y);
		printf("r.dir.x: %f, r.dir.y: %f\nr.side.x: %f, r.side.y: %f\nr.delta.x: %f, r.delta.y:%f\n", r.dir.x, r.dir.y, r.side.x, r.side.y, r.delta.x, r.delta.y); */
		dda(data, &r);
		//printf("r.wall_dist: %f\n", r.wall_dist);
		draw_vert(data, x, r.wall_dist);
		printf("\n\n\n");
	}
	//mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
}