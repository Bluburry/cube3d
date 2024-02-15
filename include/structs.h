#ifndef	STRUCTS_H
# define STRUCTS_H

# include "../mlx_linux/mlx_int.h"
# include "../mlx_linux/mlx.h"

typedef struct s_map
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
}	t_map;

typedef struct s_image
{
	void			*mlx_img;
	unsigned int	*addr;
}	t_image;

typedef struct s_minimap
{
	t_image			img;
	int				width;
	int				height;
	int				map_size;
}	t_minimap;

typedef struct s_pos
{
	double			x;
	double			y;
}	t_vector;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}	t_player;

typedef struct s_raycast
{
	double		camera_x;
	double		camera_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
	t_vector	cast_vector;
	t_vector	sidedist;
	t_vector	deltadist;
}	t_raycast;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	double		pos_x;
	double		pos_y;
	t_image		img;
	t_map		new_map;
	t_vector	dir;
	t_minimap	minimap;
	t_vector	*stk;
	t_raycast	raycast;
	t_player	player;
}	t_data;

#endif

