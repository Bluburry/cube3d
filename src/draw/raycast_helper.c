#include "cube.h"

static void	texture_calc(t_data *data, t_raycast *r)
{
	if (r->side_hit == 1 || r->side_hit == 3)
		r->wall_x = data->player.pos.x + r->wall_dist * r->dir.x;
	else
		r->wall_x = data->player.pos.y + r->wall_dist * r->dir.y;
	r->wall_x -= floor(r->wall_x);
	r->tex_x = (int)(r->wall_x * (double) IMG_WIDTH);
	if (((r->side_hit == 0 || r->side_hit == 2) && r->dir.x < 0) || \
		((r->side_hit == 1 || r->side_hit == 3) && r->dir.x > 0))
		r->tex_x = IMG_WIDTH - r->tex_x - 1;
	r->tex_step = 1.0 * IMG_HEIGHT / r->line_height;
	r->tex_pos = (r->draw_start - HEIGHT / 2 + \
		r->line_height / 2) * r->tex_step;
}

static void	draw_wall(t_data *data, t_raycast *r, int x, int y)
{
	auto unsigned int clr = WALL_CLR;
	texture_calc(data, r);
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
		else
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
