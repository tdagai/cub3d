/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:25:11 by teva              #+#    #+#             */
/*   Updated: 2020/10/15 07:54:59 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	create_scene(t_info *s)
{
	int	temp[2];

	s->init = mlx_init();
	mlx_get_screen_size(s->init, &temp[0], &temp[1]);
	s->res.x > temp[0] ? s->res.x = temp[0] : 0;
	s->res.y > temp[1] ? s->res.y = temp[1] : 0;
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

int			main()
{
	t_info	*s;

	s = (t_info *)ft_memalloc(sizeof(t_info));
	s->res.x = 1280;
	s->res.y = 720;
	create_scene(s);
	return(0);
}

