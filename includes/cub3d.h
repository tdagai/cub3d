/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:52:09 by teva              #+#    #+#             */
/*   Updated: 2020/10/18 14:48:28 by teva             ###   ########.fr       */
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
t_info			*manage_file_data(char **split, t_info *s);
t_info			*set_resolution(char **split, t_info *s);

/* **************** */
/*	errors.c funcs  */
/* **************** */

void			ft_error(int error_num);

/* ************************* */
/*	funcs_that_free.c funcs  */
/* ************************* */

void			free_split(char **split);

/* ********************** */
/*	set_textures.c funcs  */
/* ********************** */

t_info			*set_north_texture(char **split, t_info *s);
t_info			*set_south_texture(char **split, t_info *s);
t_info			*set_west_texture(char **split, t_info *s);
t_info			*set_east_texture(char **split, t_info *s);
t_info			*set_sprite_texture(char **split, t_info *s);

#endif
