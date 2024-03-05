#include "cube.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf("WHERE IS THE THE MAP!!\n");
		return (0);
	}
	init_data(&data);
	init_map(&data);
	if (read_file(av[1], &data))
	{
		printf("Invalid Map1\n");
		return (1);
	}
	
	if (validate_map(&data))
	{
		printf("Invalid Map2.\n");
		return (1);
	}
	get_player_position(&data);

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3D");

/*	data.img.mlx_img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.img.addr = (unsigned int *)mlx_get_data_addr(
			data.img.mlx_img, &data.img.bpp, &data.img.sl, &data.img.ed);
	auto	int	text_height, text_width;
	data.img.mlx_img = mlx_xpm_file_to_image(data.mlx, "./textures/blue.xpm", &text_width, &text_height);
	data.img.addr = (unsigned int *)mlx_get_data_addr(
			data.img.mlx_img, &data.img.bpp, &data.img.sl, &data.img.ed);
	mlx_put_image_to_window(data.mlx, data.win, data.img.mlx_img, 100, 100);
*/


	mlx_hook(data.win, 17, 1L << 17, &on_destroy, &data);
	mlx_hook(data.win, 2, 1L << 0, &close_window, &data);

	// init_texture(&data);
	raycast_attempt(&data);
	// init_minimap(&data);
	// draw_rectangles(&data);
	// draw_player(&data);

	// mlx_put_image_to_window(data.mlx, data.win, 
	// 	data.minimap.img.mlx_img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
