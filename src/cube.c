#include "cube.h"

static void	validate(char *fl, t_data *data)
{
	if (read_file(fl, data))
	{
		printf("Invalid Map - Read File\n");
		on_destroy(data);
	}
	data->new_map.rows = get_map_rows(fl);
	if (data->new_map.rows < 3)
	{
		printf("Invalid map - row count.\n");
		on_destroy(data);
	}
	data->new_map.map = get_map(fl, data->new_map.rows);
	if (!data->new_map.map)
	{
		printf("Error getting map.\n");
		on_destroy(data);
	}
	if (validate_map(data))
	{
		printf("Invalid Map - Validate Map\n");
		on_destroy(data);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		printf("WHERE IS THE THE MAP!!\n");
		return (1);
	}

	init_data(&data);
	validate(av[1], &data);

	get_player_position(&data);

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3D");

	create_raycast_image(&data, &data.img, &data.new_map);
	raycast_attempt(&data);

	mlx_hook(data.win, 17, 1L << 17, &on_destroy, &data);
	mlx_hook(data.win, 2, 1L << 0, &user_input, &data);	
	mlx_loop(data.mlx);

	return (0);
}
