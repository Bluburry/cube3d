/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:34:30 by tpinto-e          #+#    #+#             */
/*   Updated: 2024/04/08 17:07:49 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../mlx_linux/mlx_int.h"
# include "../mlx_linux/mlx.h"

typedef struct s_texture
{
	unsigned int	*addr;
	void			*img;
	char			*path;
	int				width;
	int				height;
	int				bpp;
	int				sl;
	int				ed;
}	t_texture;

// Struct to deal with map.cub
typedef struct s_map
{
	char			**map;
	int				rows;
	int				columns;
	t_texture		no;
	t_texture		so;
	t_texture		we;
	t_texture		ea;
	unsigned int	floor;
	unsigned int	sky;
}	t_map;

// Image struct -> It's needed to use MLX lib.
typedef struct s_image
{
	void			*mlx_img;
	unsigned int	*addr;
	int				bpp;
	int				sl;
	int				ed;
}	t_image;

// Minimap in the game.
typedef struct s_minimap
{
	t_image	img;
	int		width;
	int		height;
	int		bpp;
	int		sl;
	int		end;
}	t_minimap;

// Struct to save double.
typedef struct s_stk
{
	double	x;
	double	y;
}		t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	double		p_ang;
}	t_player;

typedef struct s_raycast
{
	double		wall_dist;
	double		wall_x;
	double		tex_step;
	double		tex_pos;
	double		angle;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side_hit;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			tex_y;
	t_vector	camera;
	t_vector	dir;
	t_vector	side;
	t_vector	delta;
}	t_raycast;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_image		img;	
	t_map		new_map;
	t_vector	dir;
	t_player	player;
	t_minimap	minimap;
	bool		bonus;
}	t_data;

#endif
