/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 12:25:11 by teva              #+#    #+#             */
/*   Updated: 2020/10/20 01:32:59 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

static void	init_game(int num_args, char *filename)
{
	int			screen_size[2];
	t_info		*s;

	num_args != 2 ? ft_error(ARG_ERROR) : 0;
	if (ft_file_extension(filename, ".cub") == 0)
		ft_error(FILE_EXTENSION_ERROR);
	s = (t_info *)ft_memalloc(sizeof(t_info));
	s->map_dim.x = 0;
	s->map_dim.y = 0;
	s = read_cub_file(filename, s);

	printf("scrren resolution x:	%i\n", s->res.x);
	printf("scrren resolution y:	%i\n", s->res.y);
	printf("north texture path:		%s\n", s->north);
	printf("south texture path:		%s\n", s->south);
	printf("west texture path:		%s\n", s->west);
	printf("east texture path:		%s\n", s->east);
	printf("sprite texture path:	%s\n", s->sprite);
	printf("floor color in RGB:		%i %i %i\n", s->floor_color[0], s->floor_color[1],\
												 s->floor_color[2]);
	printf("ceiling color in RGB:		%i %i %i\n", s->ceiling_color[0], s->ceiling_color[1],\
												 	 s->ceiling_color[2]);
	for (int i = 0; i < s->map_dim.y; i++)
		printf("%s\n", s->map[i]);

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

int			close_program(t_info *s)
{
	free_struct(s);
	exit(0);
}

int			main(int ac, char **av)
{
	init_game(ac, av[1]);
	return (0);
}
