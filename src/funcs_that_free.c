/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_that_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 23:31:14 by teva              #+#    #+#             */
/*   Updated: 2020/10/20 01:42:58 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_split(char **split)
{
	int	ctr;

	ctr = 0;
	while (split && split[ctr])
		ft_memdel((void **)&split[ctr++]);
	free(split);
}

void	free_struct(t_info *s)
{
	int ctr;

	ctr = 0;
	ft_memdel((void **)&s->north);
	ft_memdel((void **)&s->south);
	ft_memdel((void **)&s->west);
	ft_memdel((void **)&s->east);
	ft_memdel((void **)&s->sprite);
	while (ctr < s->map_dim.y)
		ft_memdel((void **)&s->map[ctr++]);
	free (s->map);
	free(s);
}
