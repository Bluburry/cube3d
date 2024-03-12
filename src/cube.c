#include "cube.h"

static int	validate(char *fl, t_data *data)
{
	char	**map_i;

	if (read_file(fl, data))
	{
		printf("Invalid Map - Read File\n");
		return (1);
	}
	data->new_map.rows = get_map_rows(fl);
	map_i = get_map(fl, data->new_map.rows);
	if (!map_i)
	{
		printf("Error getting map.\n");
		return (1);
	}
	if (data->new_map.rows < 3 || \
		!validate_map(map_i, data->new_map.rows))
	{
		printf("Invalid Map - Validate Map\n");
		clear_matrix(map_i, -1);
		on_destroy(data);
		return (1);
	}
	data->new_map.map = map_i;
	return (0);
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
	if (validate(av[1], &data))
		return (1);

	create_raycast_image(&data, &data.img, &data.new_map);
	get_player_position(&data);

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3D");

	raycast_attempt(&data);

	mlx_hook(data.win, 17, 1L << 17, &on_destroy, &data);
	mlx_hook(data.win, 2, 1L << 0, &user_input, &data);	
	mlx_loop(data.mlx);

	return (0);
}
