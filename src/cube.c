/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluburry <bluburry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:56:55 by jegger-s          #+#    #+#             */
/*   Updated: 2024/02/13 20:08:00by bluburry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	init(t_data *data, t_image *img, \
		t_minimap *minimap, t_stk *stk)
{
	data->pos_y = 0;
	data->pos_x = 0;
	data->mlx = NULL;
	data->win = NULL;
	img->mlx_img = NULL;
	img->addr = NULL;
	minimap->map_size = 10;
	stk = NULL;
	data->img = *img;
	data->minimap = *minimap;
	data->stk = stk;
	data->stk = malloc(sizeof(t_stk) * 720);
}

int	init2(t_data *data, char **av)
{
	init_map(data);
	read_file(av[1], data);
	if (validate_map(data))
	{
		printf("Invalid map.\n");
		free(data->stk);
		return (1);
	}
	get_player_position(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 720, 420, "Cub3D");
	init_minimap(data);
	draw_lines(data);
	draw_rectangles(data);
	draw_player(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_image		img;
	t_minimap	minimap;
	t_stk		*stk;

	if (ac != 2)
	{
		printf("Invalid number of arguments.\n");
		return (0);
	}
	init(&data, &img, &minimap, stk);
	if (init2(&data, av))
		return (0);
	mlx_put_image_to_window(data.mlx, data.win, \
		data.minimap.img.mlx_img, 0, 0);
	mlx_hook(data.win, 17, 1L << 2, &on_destroy, &data);
	mlx_hook(data.win, 2, 1L << 0, &close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
