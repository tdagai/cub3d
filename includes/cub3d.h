/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:52:09 by teva              #+#    #+#             */
/*   Updated: 2020/10/21 18:56:28 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "structs.h"
# include "macros.h"

# include <stdio.h>

/* ************** */
/*	main.c funcs  */
/* ************** */

static void		create_scene(t_info *s);
int				close_program(t_info *s);

/* ********************** */
/*	on_key_press.c funcs  */
/* ********************** */

int				on_key_press(int key_code, t_info *s);

/* ******************* */
/*	read_file.c funcs  */
/* ******************* */

t_info			*read_cub_file(char *filename, t_info *s);
t_info			*read_map(char *filename, t_info *s);
t_info			*manage_file_data(char *line, t_info *s);
t_info			*set_resolution(char **split, t_info *s);

/* ************** */
/*	misc.c funcs  */
/* ************** */

void			ft_error(int error_num);
int				ok_letters(char c);

/* ************************* */
/*	funcs_that_free.c funcs  */
/* ************************* */

void			free_split(char **split);
void			free_struct(t_info *s);

/* ********************** */
/*	set_textures.c funcs  */
/* ********************** */

t_info			*set_north_texture(char **split, t_info *s);
t_info			*set_south_texture(char **split, t_info *s);
t_info			*set_west_texture(char **split, t_info *s);
t_info			*set_east_texture(char **split, t_info *s);
t_info			*set_sprite_texture(char **split, t_info *s);

/* **************** */
/*	colors.c funcs  */
/* **************** */

t_info			*set_color_rgb(char **split, t_info *s, char identifier);

/* ****************** */
/*	init_map.c funcs  */
/* ****************** */

char			**init_map(int len, int wid, char fill);

/* ********************** */
/*	validate_map.c funcs  */
/* ********************** */

void			validate_map(t_info *s);
int				validate_letter_in_map(t_info *s, int posx, int posy);
int				validate_sprite_in_map(t_info *s, int posx, int posy);
int				validate_empty_in_map(t_info *s, int posx, int posy);

#endif
