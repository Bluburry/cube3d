/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:39:56 by tpinto-e          #+#    #+#             */
/*   Updated: 2024/04/08 18:42:26 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	check_file_cont(char *fl)
{
	char	*cub;

	cub = ft_strrchr(fl, '.');
	if (!cub && ft_strcmp(cub, ".cub"))
	{
		print_errors("Invalid map file format.\n");
		exit (1);
	}
	auto int fd = open(fl, O_RDONLY);
	if (fd < 1)
	{
		print_errors("Could not open file.\n");
		close(fd);
		exit(1);
	}
	close(fd);
}

static void	check_file(int argc, char **argv)
{
	if (argc != 2)
	{
		print_errors("No map file specified.\n");
		exit(1);
	}
	auto char *fl;
	fl = argv[1];
	auto int i = 0;
	while (fl[i])
		i++;
	if (i < 5 || ft_strncmp(fl + i - 4, ".cub", 4))
	{
		print_errors("Invalid map file format.\n");
		exit (1);
	}
	check_file_cont(argv[1]);
}

static void	validate(char *fl, t_data *data)
{
	auto int err = read_file(fl, data);
	if (err)
	{
		printf("err: %d\n", err);
		print_errors("Invalid File - Read File\n");
		on_destroy(data);
	}
	data->new_map.rows = get_map_rows(fl);
	if (data->new_map.rows < 3)
	{
		print_errors("Invalid map.\n");
		on_destroy(data);
	}
	data->new_map.map = get_map(fl, data->new_map.rows);
	if (!data->new_map.map)
	{
		print_errors("Error getting map.\n");
		on_destroy(data);
	}
	if (validate_map(data))
	{
		print_errors("Invalid Map - Validate Map\n");
		on_destroy(data);
	}
	data->new_map.columns = get_map_columns(data);
}

int	main(int ac, char **av)
{
	auto t_data data;
	check_file(ac, av);
	init_data(&data);
	validate(av[1], &data);
	get_player_position(&data);
	data.bonus = false;
	if (!ft_strcmp(av[0], "./cub3d_bonus"))
		data.bonus = true;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3D");
	create_raycast_image(&data);
	raycast_attempt(&data);
	if (data.bonus)
		init_minimap(&data);
	if (data.bonus)
		draw_movements(&data);
	if (data.bonus)
		mlx_mouse_move(data.mlx, data.win, WIDTH / 2, HEIGHT / 2);
	mlx_hook(data.win, 17, 1L << 17, &on_destroy, &data);
	mlx_hook(data.win, 2, 1L << 0, &user_input, &data);
	if (data.bonus)
		mlx_hook(data.win, 6, 1L << 6, &mouse_input, &data);
	mlx_loop(data.mlx);
	return (0);
}
