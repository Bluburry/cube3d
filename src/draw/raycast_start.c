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
	// printf("data->player.pos.x: %f | data->player.pos.y: %f\n\n", data->player.pos.x, data->player.pos.y);
}

void	dda(t_data *data, t_raycast *r)
{
	auto double ang = data->player.p_ang;
	r->side_hit = 0;
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
	//printf("side_hit: %d, ray hit coordinates: %d, %d\n", r->side_hit, r->map_y, r->map_x);
	//printf("x: %f | before ang: %f | after ", r->camera.x, ang);
	if (r->side_hit == 0)
	{
		r->wall_dist = (r->side.x - r->delta.x);
		ang += atan(r->camera.x / r->wall_dist);
		if (ang >= PI * 2)
			ang -= PI * 2;
		else if (ang < 0)
			ang += PI * 2;
		if (ang < PI / 2 || ang > PI * 3 / 2)
			r->side_hit = 2;
	}
	else
	{
		r->wall_dist = (r->side.y - r->delta.y);
		ang += atan(r->camera.x / r->wall_dist);
		if (ang > PI * 2)
			ang -= PI * 2;
		else if (ang < 0)
			ang += PI * 2;
		if (ang > PI)
			r->side_hit = 3;
	}
	/* switch(r->side_hit)
	{
		case 0:
			printf("ray hit west wall\n");
			break;
		case 1:
			printf("ray hit north wall\n");
			break;
		case 2:
			printf("ray hit east wall\n");
			break;
		case 3:
			printf("ray hit south wall\n");
			break;
		default:
			printf("wtf\n");
			break;
	} */
	// printf("ang: %f\n", ang);
	// printf("r->wall_dist: %f\n", r->wall_dist);
}

#define WALL_CLR 0x0000FF00
#define REST_CLR 0x00000000

void	draw_wall(t_data *data, t_raycast *r, int x, int y)
{
	if (r->side_hit == 0 || r->side_hit == 2)
		r->wall_x = data->player.pos.y + r->wall_dist * data->player.dir.y;
	else
		r->wall_x = data->player.pos.x + r->wall_dist * data->player.dir.x;
	r->wall_x -= floor(r->wall_x);
	r->tex_x = (int)(r->wall_x * (double) IMG_WIDTH);
	if (((r->side_hit == 0 || r->side_hit == 2) && r->dir.x > 0) || \
		((r->side_hit == 1 || r->side_hit == 3) && r->dir.x < 0))
		r->tex_x = IMG_WIDTH - r->tex_x - 1;
	r->tex_step = 1.0 * IMG_HEIGHT / r->line_height;
	r->tex_pos = (r->draw_start - HEIGHT / 2 + r->line_height / 2) * r->tex_step;
	auto unsigned int clr = WALL_CLR;
	while (y++ < r->draw_end)
	{
		r->tex_y = (int) r->tex_pos & (IMG_HEIGHT - 1);
		r->tex_pos += r->tex_step;
		if (r->side_hit == 0)
			clr = data->new_map.we.addr[r->tex_y * IMG_WIDTH + r->tex_x];
		else if (r->side_hit == 1)
			clr = data->new_map.no.addr[r->tex_y * IMG_WIDTH + r->tex_x];
		else if (r->side_hit == 2)
			clr = data->new_map.ea.addr[r->tex_y * IMG_WIDTH + r->tex_x];
		else if (r->side_hit == 3)
			clr = data->new_map.so.addr[r->tex_y * IMG_WIDTH + r->tex_x];
		if (clr > 0)
			data->img.addr[y * WIDTH + x] = clr;
	}
}

void	draw_vert(t_data *data, t_raycast *r, int x)
{
	r->line_height = (int)(HEIGHT / r->wall_dist);
	r->draw_start = -r->line_height / 2 + HEIGHT / 2;
	r->draw_end = r->line_height / 2 + HEIGHT / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	if (r->draw_end >= HEIGHT)
		r->draw_end = HEIGHT - 1;
	auto int y = -1;
	while (++y < r->draw_start)
	{
		data->img.addr[y * WIDTH + x] = data->new_map.sky;
	}
	draw_wall(data, r, x, y);
	y = r->draw_end;
	while (y++ < HEIGHT)
	{
		data->img.addr[y * WIDTH + x] = data->new_map.floor;
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
	data->img.addr = (unsigned int *)mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.sl, &data->img.ed);
	data->new_map.no.img = mlx_xpm_file_to_image(data->mlx, "./maps/textures/bricks.xpm", &data->new_map.no.width, &data->new_map.no.height);
	data->new_map.no.addr = (unsigned int *) mlx_get_data_addr(data->new_map.no.img, &data->new_map.no.bpp, &data->new_map.no.sl, &data->new_map.no.ed);
	data->new_map.so.img = mlx_xpm_file_to_image(data->mlx, "./maps/textures/dirt.xpm", &data->new_map.so.width, &data->new_map.so.height);
	data->new_map.so.addr = (unsigned int *) mlx_get_data_addr(data->new_map.so.img, &data->new_map.so.bpp, &data->new_map.so.sl, &data->new_map.so.ed);
	data->new_map.we.img = mlx_xpm_file_to_image(data->mlx, "./maps/textures/coal.xpm", &data->new_map.we.width, &data->new_map.we.height);
	data->new_map.we.addr = (unsigned int *) mlx_get_data_addr(data->new_map.we.img, &data->new_map.we.bpp, &data->new_map.we.sl, &data->new_map.we.ed);
	data->new_map.ea.img = mlx_xpm_file_to_image(data->mlx, "./maps/textures/mud.xpm", &data->new_map.ea.width, &data->new_map.ea.height);
	data->new_map.ea.addr = (unsigned int *) mlx_get_data_addr(data->new_map.ea.img, &data->new_map.ea.bpp, &data->new_map.ea.sl, &data->new_map.ea.ed);
	/* printf("\n\n\n\t--- new line ---\n");
	printf("player data:\ndir, x: %f | y: %f\np_ang: %f\n", data->player.pos.x, data->player.pos.y, data->player.p_ang); */
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
		draw_vert(data, &r, x);
		// printf("\n\n\n");
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
}
