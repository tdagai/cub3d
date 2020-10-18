/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:00:35 by teva              #+#    #+#             */
/*   Updated: 2020/10/18 00:05:45 by teva             ###   ########.fr       */
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
	char		*floor_color;
	char		*cieling_color;
	char		**map;
	int			pixels;
	t_xy		res;
}				t_info;

#endif
