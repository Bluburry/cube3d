#ifndef CUBE_H
# define CUBE_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "structs.h"

# define WIDTH			720
# define HEIGHT			420
# define MOVE_LEFT		97
# define MOVE_RIGHT		100
# define MOVE_UP		119
# define MOVE_DOWN		115
# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363

// --- draw ---

// draw.c
void	draw_rectangle(t_data *data, int x, int y, long color);
void	draw_rectangles(t_data *data);
void	draw_line(t_data *data, t_vector pos1, t_vector pos2, long color);
void	draw_lines(t_data *data);
void	draw_player(t_data *data);


// --- hooks ---

// hook_functions.c
int		close_window(int keycode, t_data *data);
int		on_destroy(t_data *data);
void	movements(int keycode, t_data *data);


// --- map ---

// init.c
void	init_map(t_data *data);
void	set_player_position(t_data *data, int x, int y, int pos);
void	init_data(t_data *data);
void	init_minimap(t_data *data);
void	init_ray(t_raycast *ray);

// minimap.c
void	get_player_position(t_data *data);

// read_file.c
void	read_file(char *file, t_data *data);

// save_map.c
int		save_texture_path(char *path, t_data *data);
void	save_map(char *line, t_data *data);

// validate_map
int	check_matrix(t_data *data, int i, int j);
int	check_closed(t_data *data, int i, int j);
int	check_surrounded(char *map, int rows, int i, int j);
int	validate_map(t_data *data);


#endif