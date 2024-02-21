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
	read_file(av[1], &data);
	if (validate_map(&data))
		printf("Invalid Map.\n");
	get_player_position(&data);

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Cub3D");
	mlx_key_hook(data.win, close_window, &data);
	mlx_hook(data.win, 17, 1L << 17, &on_destroy, &data);

	data.player.dir.y = -1;
	data.player.dir.x = 0;
	data.player.plane.x = 0.6;
	data.player.plane.y = 0;
	for (int i = 0; i < data.new_map.rows; i++) {
		for (int j = 0; j < data.new_map.columns; j++) {
			printf("%c", data.new_map.map[i][j]);
		}
		printf("\n");
	}
	raycast_attempt(&data);
	//init_minimap(&data);
	//draw_lines(&data);
	//draw_rectangles(&data);
	//draw_player(&data);

	//mlx_put_image_to_window(data.mlx, data.win, 
		//data.minimap.img.mlx_img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
