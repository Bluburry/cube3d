#ifndef	MAP_H
# define MAP_H

# include "../mlx_linux/mlx_int.h"
# include "../mlx_linux/mlx.h"

// Struct to deal with map.cub
typedef struct s_map
{
	char	**map; // Map array [x, y]
	int		rows; 
	int		columns;
	char	*no_path; // North path from map.cub
	char	*so_path; // South path from map.cub
	char	*we_path; // West path from map.cub
	char	*ea_path; // East path from map.cub
	int		*floor;	// Colour of the floor
	int		*sky; // Colour of the sky
}				t_map;

// Image struct -> It's needed to use MLX lib.
typedef struct s_image
{
	void			*mlx_img;
	unsigned int	*addr;
}				t_image;

// Minimap in the game.
typedef struct s_minimap
{
	t_image			img; // It's a different image from the game, so it must have its own.
	int				width;
	int				height;
	int				map_size;
}				t_minimap;

// Struct to save double.
typedef struct s_stk
{
	double			x;
	double			y;
}				t_stk;

typedef struct s_dir // Useless? We can use s_stk or the other way around.
{
	double	x;
	double	y;
}				t_dir;

typedef struct s_player
{
	t_stk		pos; // Player position in the map get from map.cub
}				t_player;

typedef	struct s_raycast
{
	t_stk	cast_dir; //Raycast direction
}				t_raycast;

typedef struct s_data
{
	void		*mlx;	// MLX main pointer
	void		*win; 	// Win Pointer
	int			x; 		// Window Width
	int			y; 		// Window Height
	t_image		img;	
	t_map		new_map;
	t_dir		dir;
	t_minimap	minimap;
	t_raycast	raycast;
	t_player	player;
}				t_data;

#endif

