#include "cube.h"

static void	validate(char *fl, t_data *data)
{
	if (read_file(fl, data))
	{
		printf("Invalid File - Read File\n");
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
	// on_destroy(data);
	/* if (validate_map(data))
	{
		printf("Invalid Map - Validate Map\n");
		on_destroy(data);
	} */
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

	/* printf("row count : %d\n", data.new_map.rows);
	auto int i = -1, j;
	while (data.new_map.map[++i]) {
		j = -1;
		while (data.new_map.map[i][++j]) {
			printf("%c", data.new_map.map[i][j]);
		}
		printf("\n");
	}
	printf("NO: %s\nSO: %s\nEA: %s\nWE: %s\n", data.new_map.no.path, \
		data.new_map.so.path, data.new_map.ea.path, data.new_map.we.path); */

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3D");

	create_raycast_image(&data);
	raycast_attempt(&data);

	mlx_hook(data.win, 17, 1L << 17, &on_destroy, &data);
	mlx_hook(data.win, 2, 1L << 0, &user_input, &data);	
	mlx_loop(data.mlx);

	return (0);
}
