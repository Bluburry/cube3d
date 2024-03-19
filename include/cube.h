/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluburry <bluburry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:09:59 by bluburry          #+#    #+#             */
/*   Updated: 2024/03/19 19:52:54 by bluburry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <stdbool.h>
# include "libft.h"
# include "structs.h"
# include "keys.h"

// --- calcs ---

// --- draw ---

// raycast_start
void	raycast_attempt(t_data *data);

// raycast_helper
void	draw_vert(t_data *data, t_raycast *r, int x);

// -- extras ---

// extras.c
char	*cpy_line(const char *src);

// checker.c
int		final_checker(int fd, char *checker, char *ptr);

// rgb.c
int		creatergb(unsigned int *clr, char *sub_str);

// --- free ---

// clean.c
void	clear_matrix(char **mat, int s);
void	destroy_paths(t_data *data);
void	destroy_imgs(t_data *data);

// --- hooks ---

// hook_functions.c
void	move(int keycode, t_data *data);
void	rotate(int keycode, t_data *data);

// hook_handle.c
int		user_input(int keycode, t_data *data); 
int		on_destroy(t_data *data);

// --- init ---

// init.c
void	init_map(t_data *data);
void	set_player_position(t_data *data, int x, int y, int pos);
void	init_data(t_data *data);
void	init_minimap(t_data *data);

// raycast_images.c
void	create_raycast_image(t_data *data);

// --- map ---

// minimap.c
void	get_player_position(t_data *data);

// read_file.c
int		read_file(char *file, t_data *data);

// save_map.c
int		save_texture_path(char *path, t_data *data);
int		save_map(char *line, t_data *data);

// new_validate_map.c
int		get_map_rows(char *file);
char	**get_map(char *file, int rows);

// validate_map
int	check_matrix(t_data *data, int i, int j);
int	check_closed(t_data *data, int i, int j);
int	check_surrounded(char *map, int rows, int i, int j);
int	validate_map(t_data *data);

#endif