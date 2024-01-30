/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluburry <bluburry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:56:55 by jegger-s          #+#    #+#             */
/*   Updated: 2024/01/30 18:16:02 by bluburry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


int	main(int ac, char **av)
{
	(void)ac;

	t_data		data;
	t_img		img;
	t_minimap	minimap;
	t_stk		*stk;

	data.pos_y = 0;
	data.pos_x = 0;
	data.mlx = NULL;
	data.win = NULL;

	img.mlx_img = NULL;
	img.addr = NULL;	

	minimap.map_size = 10;

	stk = NULL;

	data.img = img;
	data.minimap = minimap;


	data.stk = stk;
	data.stk = malloc(sizeof(t_stk) * 720);

	init_map(&data);
	read_file(av[1], &data);
	if (validate_map(&data))
		printf("Invalid Map.\n");
	get_player_position(&data);

	data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 720, 420, "Cub3D");
    init_minimap(&data);
    draw_lines(&data);
    draw_rectangles(&data);
    draw_player(&data);
	mlx_put_image_to_window(data.mlx, data.win,
		data.minimap.img.mlx_img, 0, 0);

	mlx_hook(data.win, 17, 1L << 2, &on_destroy, &data);
    mlx_hook(data.win, 2, 1L << 0, &close_window, &data);

    mlx_loop(data.mlx);
}
