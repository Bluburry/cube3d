/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:44:19 by jegger-s          #+#    #+#             */
/*   Updated: 2024/04/09 20:44:21 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	set_direction(t_player *player, int pos)
{
	if (pos == 'S')
	{
		player->p_ang = PI * 3 / 2;
		player->dir.y = 1.0f;
		player->plane.x = -0.66;
	}
	else if (pos == 'N')
	{
		player->p_ang = PI / 2;
		player->dir.y = -1.0f;
		player->plane.x = 0.66;
	}
	else if (pos == 'E')
	{
		player->p_ang = PI;
		player->dir.x = 1.0f;
		player->plane.y = 0.66;
	}
	else if (pos == 'W')
	{
		player->dir.x = -1.0f;
		player->plane.y = -0.66;
	}
}

void	set_player_position(t_data *data, int x, int y, int pos)
{
	data->player.pos.y = (double)x + 0.5;
	data->player.pos.x = (double)y + 0.5;
	data->player.p_ang = 0;
	data->player.dir.x = 0.0f;
	data->player.dir.y = 0.0f;
	data->player.plane.x = 0;
	data->player.plane.y = 0;
	set_direction(&data->player, pos);
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
	t_minimap	minimap;

	img.mlx_img = NULL;
	img.addr = NULL;
	player.pos.x = 0;
	player.pos.y = 0;
	player.plane.x = 0;
	player.plane.y = 0;
	player.p_ang = 0;
	player.dir.x = 0;
	player.dir.y = 0;
	minimap.height = 50;
	minimap.width = 50;
	minimap.img.mlx_img = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->img = img;
	data->minimap = minimap;
	data->player = player;
	init_map(data);
}

void	init_minimap(t_data *data)
{
	data->minimap.width = data->new_map.columns * MINIMAP_SZ;
	data->minimap.height = data->new_map.rows * MINIMAP_SZ;
	data->minimap.img.mlx_img = mlx_new_image(data->mlx, \
		data->minimap.width, data->minimap.height);
	data->minimap.img.addr = (unsigned int *) \
		mlx_get_data_addr(data->minimap.img.mlx_img, &data->minimap.bpp, \
		&data->minimap.sl, &data->minimap.end);
}
