/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 20:44:50 by jegger-s          #+#    #+#             */
/*   Updated: 2024/04/09 20:44:51 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	draw_rectangle(t_data *data, int x, int y, long color)
{
	int	i;
	int	j;

	x *= MINIMAP_SZ;
	y *= MINIMAP_SZ;
	i = -1;
	while (++i < MINIMAP_SZ)
	{
		j = -1;
		while (++j < MINIMAP_SZ)
		{
			data->minimap.img.addr[(y + i) * data->new_map.columns \
				* MINIMAP_SZ + x + j] = color;
		}
	}
}

void	draw_rectangles(t_data *data)
{
	auto int i = -1, j;
	while (data->new_map.map[++i])
	{
		j = -1;
		while (data->new_map.map[i][++j])
			draw_rectangle(data, j, i, MM_CLR);
	}
	i = -1;
	while (data->new_map.map[++i])
	{
		j = -1;
		while (data->new_map.map[i][++j])
		{
			if (data->new_map.map[i][j] == '1')
				draw_rectangle(data, j, i, MM_W_CLR);
		}
	}
}

void	draw_player(t_data *data)
{
	draw_rectangle(data, (int)data->player.pos.x, \
		(int)data->player.pos.y, 0x00FF0000);
}

void	draw_movements(t_data *data)
{
	draw_rectangles(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->minimap.img.mlx_img, 0, 0);
}
