#ifndef	MAP_H
# define MAP_H

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
}				t_map;

typedef struct s_image
{
	void			*mlx_img;
	unsigned int	*addr;
}				t_image;

typedef struct s_minimap
{
	t_image			img;
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
	t_image		img;
	t_map		new_map;
	t_dir		dir;
	t_minimap	minimap;
	t_stk		*stk;
}				t_data;

#endif

