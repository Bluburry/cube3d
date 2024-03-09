#include "cube.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf("WHERE IS THE THE MAP!!\n");
		return (1);
	}
	init_data(&data);
	if (read_file(av[1], &data))
	{
		printf("Invalid Map - Read File\n");
		return (1);
	}
	
	if (validate_textures(&data))
	{
		printf("Invalid Map - Validate Textures\n");
		return (1);
	}
	if (validate_map(&data))
	{
		printf("Invalid Map - Validate Map\n");
		return (1);
	}

	get_player_position(&data);

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3D");

	raycast_attempt(&data);

	mlx_hook(data.win, 17, 1L << 17, &on_destroy, &data);
	mlx_hook(data.win, 2, 1L << 0, &close_window, &data);	
	mlx_loop(data.mlx);

	return (0);
}
