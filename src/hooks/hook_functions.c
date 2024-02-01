#include "cube.h"

// S=115
// D=100
// A=97
// w=119
void	draw_movements(t_data *data)
{
	draw_lines(data);
	draw_rectangles(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->minimap.img.mlx_img, 0, 0);
}
// Fazer hook so para movimentos;
int	close_window(int keycode, t_data *data)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(0);
 	}
 	if (keycode == 119)
 	{
 		data->pos_y -= 0.1;
 		draw_movements(data);
 	}
 	if (keycode == 100)
 	{
 		data->pos_x += 0.1;
 		draw_movements(data);
 	}
 	if (keycode == 97)
 	{
 		data->pos_x -= 0.1;
 		draw_movements(data);
 	}
 	if (keycode == 115)
 	{
 		data->pos_y += 0.1;
 		draw_movements(data);
 	}
	return (0);
}

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}