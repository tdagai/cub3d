/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:00:35 by teva              #+#    #+#             */
/*   Updated: 2020/10/14 16:55:20 by teva             ###   ########.fr       */
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
	t_xy		res;
}				t_info;

#endif
