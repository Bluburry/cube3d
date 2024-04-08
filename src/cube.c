#include "cube.h"

static void	check_file(int argc, char **argv)
{
	char	*fl;

	if (argc != 2)
	{
		printf("No map file specified.\n");
		exit(1);
	}
	fl = argv[1];
	auto int i = 0;
	while (fl[i])
		i++;
	if (i < 6 || ft_strncmp(fl + i - 4, ".cub", 4))
	{
		printf("Invalid map file format.\n");
		exit(1);
	}
	auto int fd = open(fl, O_RDONLY);
	if (fd < 1)
	{
		printf("Could not open file.\n");
		close(fd);
		exit(1);
	}
	close(fd);
}

static void	validate(char *fl, t_data *data)
{
	auto int err = read_file(fl, data);

	if (err)
	{
		printf("err: %d\n", err);
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
	if (validate_map(data))
	{
		printf("Invalid Map - Validate Map\n");
		on_destroy(data);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	check_file(ac, av);
	init_data(&data);
	validate(av[1], &data);
	get_player_position(&data);

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3D");

	create_raycast_image(&data);
	raycast_attempt(&data);

	init_minimap(&data);
	draw_movements(&data);

	mlx_mouse_move(data.mlx, data.win, WIDTH / 2, HEIGHT / 2);
	mlx_hook(data.win, 17, 1L << 17, &on_destroy, &data);
	mlx_hook(data.win, 2, 1L << 0, &user_input, &data);
	mlx_hook(data.win, 6, 1L << 6, &mouse_input, &data);
	mlx_loop(data.mlx);

	return (0);
}
