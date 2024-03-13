#include "cube.h"

void	create_raycast_image(t_data *data, t_image *img, t_map *new_map)
{
	img->mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = (unsigned int *)mlx_get_data_addr(img->mlx_img, &img->bpp, &img->sl, &img->ed);
	new_map->no.img = mlx_xpm_file_to_image(data->mlx, new_map->no.path, \
		&new_map->no.width, &new_map->no.height);
	new_map->so.img = mlx_xpm_file_to_image(data->mlx, new_map->so.path, \
		&new_map->so.width, &new_map->so.height);
	new_map->we.img = mlx_xpm_file_to_image(data->mlx, new_map->we.path, \
		&new_map->we.width, &new_map->we.height);
	new_map->ea.img = mlx_xpm_file_to_image(data->mlx, new_map->ea.path, \
		&new_map->ea.width, &new_map->ea.height);
	if (!new_map->no.img || !new_map->so.img || !new_map->ea.img || !new_map->we.img)
	{
		printf("Error - Invalid textures.\n");
		on_destroy(data);
	}
	new_map->no.addr = (unsigned int *) mlx_get_data_addr(new_map->no.img, \
		&new_map->no.bpp, &new_map->no.sl, &new_map->no.ed);
	new_map->so.addr = (unsigned int *) mlx_get_data_addr(new_map->so.img, \
		&new_map->so.bpp, &new_map->so.sl, &new_map->so.ed);
	new_map->we.addr = (unsigned int *) mlx_get_data_addr(new_map->we.img, \
		&new_map->we.bpp, &new_map->we.sl, &new_map->we.ed);
	new_map->ea.addr = (unsigned int *) mlx_get_data_addr(new_map->ea.img, \
		&new_map->ea.bpp, &new_map->ea.sl, &new_map->ea.ed);
}
