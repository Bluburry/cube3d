/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:26:03 by tpinto-e          #+#    #+#             */
/*   Updated: 2024/04/08 16:36:24 by tpinto-e         ###   ########.fr       */
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

// --- raycast ---

// raycast_start
void	raycast_attempt(t_data *data);

// raycast_helper
void	draw_vert(t_data *data, t_raycast *r, int x);

// -- extras ---

// extras.c
char	*cpy_line(const char *src);
int		get_map_columns(t_data *data);

// checker.c
int		final_checker(int fd, char *checker, char *ptr);

// rgb.c
int		creatergb(unsigned int *clr, char *sub_str);

// --- file_validation ---

// read_file.c
int		read_file(char *file, t_data *data);

// --- clean ---

// clean.c
void	clear_matrix(char **mat, int s);
void	destroy_paths(t_data *data);
void	destroy_imgs(t_data *data);

// --- hooks ---

// hook_functions.c
void	move(int keycode, t_data *data);
void	rotate(int keycode, double rot, t_data *data);

// hook_handle.c
int		user_input(int keycode, t_data *data); 
int		on_destroy(t_data *data);
int		mouse_input(int x, int y, t_data *data);

// --- init ---

// init.c
void	init_map(t_data *data);
void	set_player_position(t_data *data, int x, int y, int pos);
void	init_data(t_data *data);
void	init_minimap(t_data *data);

// raycast_images_init.c
void	create_raycast_image(t_data *data);

// --- map ---

// minimap.c
void	get_player_position(t_data *data);

// get_map.c
int		get_map_rows(char *file);
char	**get_map(char *file, int rows);

// validate_map
int		check_matrix(t_data *data, int i, int j);
int		check_closed(t_data *data, int i, int j);
int		check_surrounded(char *map, int rows, int i, int j);
int		validate_map(t_data *data);
int		get_row_len(char *row, int i);

// Bonus

void	draw_movements(t_data *data);
void	draw_rectangles(t_data *data);

#endif