/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:52:09 by teva              #+#    #+#             */
/*   Updated: 2020/10/17 14:12:38 by teva             ###   ########.fr       */
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

/* ********************** */
/*	read_file.c funcs	  */
/* ********************** */

char			*read_cub_file(char *filename, t_info *s);

#endif
