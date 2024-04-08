/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_images_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:35:10 by tpinto-e          #+#    #+#             */
/*   Updated: 2024/04/08 16:35:11 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	raycast_images_helper(t_data *data)
{
	data->new_map.no.addr = (unsigned int *) \
		mlx_get_data_addr(data->new_map.no.img, &data->new_map.no.bpp, \
		&data->new_map.no.sl, &data->new_map.no.ed);
	data->new_map.so.addr = (unsigned int *) \
		mlx_get_data_addr(data->new_map.so.img, &data->new_map.so.bpp, \
		&data->new_map.so.sl, &data->new_map.so.ed);
	data->new_map.we.addr = (unsigned int *) \
		mlx_get_data_addr(data->new_map.we.img, &data->new_map.we.bpp, \
		&data->new_map.we.sl, &data->new_map.we.ed);
	data->new_map.ea.addr = (unsigned int *) \
		mlx_get_data_addr(data->new_map.ea.img, &data->new_map.ea.bpp, \
		&data->new_map.ea.sl, &data->new_map.ea.ed);
}

void	create_raycast_image(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.addr = (unsigned int *)mlx_get_data_addr(data->img.mlx_img, \
		&data->img.bpp, &data->img.sl, &data->img.ed);
	data->new_map.no.img = mlx_xpm_file_to_image(data->mlx, \
	data->new_map.no.path, &data->new_map.no.width, &data->new_map.no.height);
	data->new_map.so.img = mlx_xpm_file_to_image(data->mlx, \
	data->new_map.so.path, &data->new_map.so.width, &data->new_map.so.height);
	data->new_map.we.img = mlx_xpm_file_to_image(data->mlx, \
	data->new_map.we.path, &data->new_map.we.width, &data->new_map.we.height);
	data->new_map.ea.img = mlx_xpm_file_to_image(data->mlx, \
	data->new_map.ea.path, &data->new_map.ea.width, &data->new_map.ea.height);
	if (!data->new_map.no.img || !data->new_map.so.img || \
		!data->new_map.ea.img || !data->new_map.we.img)
	{
		printf("Error - Invalid textures.\n");
		on_destroy(data);
	}
	raycast_images_helper(data);
}
