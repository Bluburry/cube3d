/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluburry <bluburry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:09:59 by bluburry          #+#    #+#             */
/*   Updated: 2024/03/11 09:48:06 by bluburry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"
# include "structs.h"
# include "keys.h"

// --- calcs ---

// --- draw ---

// raycast_start
void	raycast_attempt(t_data *data);

// raycast_helper
void	draw_vert(t_data *data, t_raycast *r, int x);

// --- hooks ---

// hook_functions.c
void	move(int keycode, t_data *data);
void	rotate(int keycode, t_data *data);

// hook_handle.c
int		user_input(int keycode, t_data *data);

// --- init ---

// init.c
void	init_map(t_data *data);
void	set_player_position(t_data *data, int x, int y, int pos);
void	init_data(t_data *data);
void	init_minimap(t_data *data);

// raycast_images.c
void	create_raycast_image(t_data *data, t_image *img, t_map *new_map);

// --- map ---

// minimap.c
void	get_player_position(t_data *data);

// read_file.c
int		read_file(char *file, t_data *data);

// save_map.c
int		save_texture_path(char *path, t_data *data);
int		save_map(char *line, t_data *data);

// validate_map
int	check_matrix(t_data *data, int i, int j);
int	check_closed(t_data *data, int i, int j);
int	check_surrounded(char *map, int rows, int i, int j);
int	validate_map(t_data *data);
int	validate_textures(t_data *data);

#endif