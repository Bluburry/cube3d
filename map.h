/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegger-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:56:13 by jegger-s          #+#    #+#             */
/*   Updated: 2023/11/03 18:56:14 by jegger-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MAP_HPP
#define	MAP_HPP

#include <fcntl.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "./libft/libft.h"

typedef	struct s_map
{
	char	**map;
	int		rows;
	int		columns;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		*floor;	
	int		*sky;	
}				t_map;

typedef struct s_img
{
	void			*mlx_img;
	unsigned int	*addr;
}				t_img;

typedef	struct s_minimap
{
	t_img			img;
	int				width;
	int				height;
	int				map_size;
}				t_minimap;

typedef struct s_stk
{
	double			x;
	double			y;
}				t_stk;

typedef struct s_dir
{
	double	x;
	double	y;
}				t_dir;

typedef struct s_data
{
	void		*mlx;
	void		*win; 	// Win Pointer
	int			x; 		// Window Width
	int			y; 		// Window Height
	double		pos_x;
	double		pos_y;
	t_img		img;
	t_map		new_map;
	t_dir		dir;
	t_minimap	minimap;
	t_stk		*stk;
}				t_data;

//Validate Map
int	validate_map(t_data *data);
int	check_surrounded(char *map, int rows, int i, int j);
int	check_matrix(t_data *data, int i, int j);
int	check_closed(t_data *data, int i, int j);

//Save Map
int		save_texture_path(char *path, t_data *data);
void	save_map(char *line, t_data *data);

//Read file
void	read_file(char *file, t_data *data);

//Saving
int		save_texture_path(char *path, t_data *data);
void	save_map(char *line, t_data *data);

// Init
void	init_map(t_data *data);

//Hooks
int	close_window(int keycode, t_data *data);
int on_destroy(t_data *data);

#endif

