#ifndef	STRUCTS_H
# define STRUCTS_H

# include "../mlx_linux/mlx_int.h"
# include "../mlx_linux/mlx.h"

// Struct to deal with map.cub
typedef struct s_map
{
	char			**map; // Map array [x, y]
	int				rows; 
	int				columns;
	char			*no_path; // North path from map.cub
	char			*so_path; // South path from map.cub
	char			*we_path; // West path from map.cub
	char			*ea_path; // East path from map.cub
	unsigned int	floor;
	unsigned int	sky;
	//int		*floor;	// Colour of the floor
	//int		*sky; // Colour of the sky
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
	t_image	img; // It's a different image from the game, so it must have its own.
	int		width;
	int		height;
	int		map_size;
}	t_minimap;

// Struct to save double.
typedef struct s_stk
{
	double	x;
	double	y;
}		t_vector;

typedef struct s_player
{
	double		angle;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}	t_player;

typedef struct s_raycast
{
	double		wall_dist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	t_vector	camera;
	t_vector	dir;
	t_vector	side;
	t_vector	delta;
}	t_raycast;

typedef struct s_data
{
	void		*mlx;	// MLX main pointer
	void		*win; 	// Win Pointer
	int			x; 		// Window Width
	int			y; 		// Window Height
	t_image		img;	
	t_map		new_map;
	t_vector	dir;
	t_minimap	minimap;
	t_raycast	raycast;
	t_player	player;
}	t_data;

# endif