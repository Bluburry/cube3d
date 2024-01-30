/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:56:55 by jegger-s          #+#    #+#             */
/*   Updated: 2023/10/25 09:56:58 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./libft/libft.h"
#include "map.h"

void	init_map(t_data *data)
{
	data->new_map.map = NULL;
	data->new_map.no_path = NULL;
	data->new_map.so_path = NULL;
	data->new_map.we_path = NULL;
	data->new_map.ea_path = NULL;
	data->new_map.floor = 0;	
	data->new_map.sky = 0;
	data->new_map.rows = 0;
	data->new_map.columns = 0;
}

void	set_player_position(t_data *data, int x, int y, int pos)
{
	if (data->pos_y == 0 && data->pos_x == 0)
	{	
		data->pos_y = (double)x + 0.5;
		data->pos_x = (double)y + 0.5;
		if (pos == 'E')
			data->dir.x = 1;
		else if (pos == 'W')
			data->dir.x = -1;
		else if (pos == 'S')
			data->dir.y = -1;
		else if (pos == 'N')
			data->dir.y = 1;
		printf("\nDirX: %f | DirY: %f\n", data->dir.x, data->dir.y);	
		return ;
	}
}

void	get_player_position(t_data *data)
{
	int		x;
	int		y;
	char 	pos;

	x = 0;
	while (data->new_map.map[x])
	{
		y = 0;
		while (data->new_map.map[x][y])
		{
			pos = data->new_map.map[x][y];
			if (pos == 'N' || pos == 'E' || pos == 'S' || pos == 'W')
				set_player_position(data, x, y, pos);
			y++;
		}
		x++;
	}

}

void	init_minimap(t_data *data)
{
	int	bpp;
	int	sl;
	int	end;

	data->minimap.width = data->new_map.columns * data->minimap.map_size;
	data->minimap.height = data->new_map.rows * data->minimap.map_size;
	data->minimap.img.mlx_img = mlx_new_image(data->mlx, data->minimap.width,
			data->minimap.height);
	data->minimap.img.addr = (unsigned int *)mlx_get_data_addr(
			data->minimap.img.mlx_img, &bpp, &sl, &end);
}

void	draw_rectangle(t_data *data, int x, int y, long color)
{
	int	i;
	int	j;

	x *= data->minimap.map_size;
	y *= data->minimap.map_size;
	i = 0;
	while (i < data->minimap.map_size)
	{
		j = 0;
		while (j < data->minimap.map_size)
		{
			data->minimap.img.addr[(y + i) * data->new_map.columns
				* data->minimap.map_size + x + j] = color;
			j++;
		}
		i++;
	}
}

void	draw_rectangles(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->new_map.rows)
	{
		j = 0;
		while (data->new_map.map[i][j])
		{
			if (data->new_map.map[i][j] == '1')
				draw_rectangle(data, j, i, 0x00FFFFFF);
			else
				draw_rectangle(data, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}

void	draw_line(t_data *data, t_stk pos1, t_stk pos2, long color)
{
	double	delta_x;
	double	delta_y;
	double	step;
	int		coord;

	delta_x = pos2.x - pos1.x;
	delta_y = pos2.y - pos1.y;
	step = fabs(delta_y);
	if (fabs(delta_x) > fabs(delta_y))
		step = fabs(delta_x);
	delta_x /= step;
	delta_y /= step;
	while (fabs(pos2.x - pos1.x) > fabs(delta_x)
		|| fabs(pos2.y - pos1.y) > fabs(delta_y))
	{
		coord = floor(pos1.y) * floor(data->minimap.width) + floor(pos1.x);
		data->minimap.img.addr[coord] = color;
		pos1.x += delta_x;
		pos1.y += delta_y;
	}
}

void	draw_lines(t_data *data)
{
	t_stk	pos1;
	t_stk	pos2;
	int		i;

	i = -1;
	pos1.y = 0;
	pos2.y = data->minimap.height;
	while (++i < data->new_map.columns)
	{
		pos1.x = i * data->minimap.map_size;
		pos2.x = i * data->minimap.map_size;
		draw_line(data, pos1, pos2, 0x3B3B3B);
	}
	i = -1;
	pos1.x = 0;
	pos2.x = data->minimap.width;
	while (++i < data->new_map.rows)
	{
		pos1.y = i * data->minimap.map_size;
		pos2.y = i * data->minimap.map_size;
		draw_line(data, pos1, pos2, 0x3B3B3B);
	}
}

void	draw_player(t_data *data)
{
	int		i;
	t_stk	pos;
	t_stk	ray_pos;

	i = 0;
	pos.x = (ceil(data->pos_x) * data->minimap.map_size)
		- (data->minimap.map_size / 2);
	pos.y = (ceil(data->pos_y) * data->minimap.map_size)
		- (data->minimap.map_size / 2);
	while (i < 720) // Change it
	{
		ray_pos.x = ceil(data->stk[i].x * data->minimap.map_size);
		ray_pos.y = ceil(data->stk[i].y * data->minimap.map_size);
		draw_line(data, pos, ray_pos, 0x0000FF00);
		i++;
	}
	draw_rectangle(data, (int)data->pos_x, (int)data->pos_y, 0x00FF0000);
}

int	main(int ac, char **av)
{
	(void)ac;

	t_data		data;
	t_img		img;
	t_minimap	minimap;
	t_stk		*stk;

	data.pos_y = 0;
	data.pos_x = 0;
	data.mlx = NULL;
	data.win = NULL;

	img.mlx_img = NULL;
	img.addr = NULL;	

	minimap.map_size = 10;

	stk = NULL;

	data.img = img;
	data.minimap = minimap;


	data.stk = stk;
	data.stk = malloc(sizeof(t_stk) * 720);

	init_map(&data);
	read_file(av[1], &data);
	if (validate_map(&data))
		printf("Invalid Map.\n");
	get_player_position(&data);

	data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, 720, 420, "Cub3D");
    init_minimap(&data);
    draw_lines(&data);
    draw_rectangles(&data);
    draw_player(&data);
	mlx_put_image_to_window(data.mlx, data.win,
		data.minimap.img.mlx_img, 0, 0);

	mlx_hook(data.win, 17, 1L << 2, &on_destroy, &data);
    mlx_hook(data.win, 2, 1L << 0, &close_window, &data);

    mlx_loop(data.mlx);
}
