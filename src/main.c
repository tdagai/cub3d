/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:25:11 by teva              #+#    #+#             */
/*   Updated: 2020/10/18 01:04:41 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

static void	create_scene(t_info *s)
{
	int	screen_size[2];

	s->init = mlx_init();
	mlx_get_screen_size(s->init, &screen_size[0], &screen_size[1]);
	s->res.x > screen_size[0] ? s->res.x = screen_size[0] : 0;
	s->res.y > screen_size[1] ? s->res.y = screen_size[1] : 0;
	s->window = mlx_new_window(s->init, s->res.x, s->res.y, "cub3D");
	s->img_ptr = mlx_new_image(s->init, s->res.x, s->res.y);
	mlx_hook(s->window, 17, 0, close_program, s);
	mlx_key_hook(s->window, on_key_press, s);
	mlx_loop(s->init);
}

int close_program(t_info *s)
{
	free(s);
	exit(0);
}

int			main(int ac, char **av)
{
	t_info	*s;

	if (ac != 2)
		ft_error(ARG_ERROR);
	s = (t_info *)ft_memalloc(sizeof(t_info));
	s = read_cub_file(av[1], s);
	printf("x:	%i\ny:	%i\nnorth:	%s\nsouth:	%s\nwest:	%s\neast:	%s\n",\
			s->res.x, s->res.y, s->north, s->south, s->west, s->east);
	create_scene(s);
	return(0);
}

