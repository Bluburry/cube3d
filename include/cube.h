/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluburry <bluburry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:09:59 by bluburry          #+#    #+#             */
/*   Updated: 2024/02/15 16:05:14 by bluburry         ###   ########.fr       */
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