/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:00:35 by teva              #+#    #+#             */
/*   Updated: 2020/10/19 18:42:38 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef	struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef	struct	s_info 
{
	void		*init;
	void		*window;
	void		*img_ptr;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
	int			floor_color[3];
	int			ceiling_color[3];
	char		**map;
	t_xy		res;
	t_xy		map_dim;
}				t_info;

#endif
