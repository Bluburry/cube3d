/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluburry <bluburry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:56:55 by jegger-s          #+#    #+#             */
/*   Updated: 2024/02/01 00:51:12 by bluburry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("WHERE IS THE THE MAP!!\n");
		return 0;
	}

	t_data		data;

	init_data(&data);
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
