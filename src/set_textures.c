/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 00:24:11 by teva              #+#    #+#             */
/*   Updated: 2020/10/18 14:48:00 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_info		*set_north_texture(char **split, t_info *s)
{
	if (ft_wordcount(split) != 2)
		ft_error(ARGS_IN_FILE_ERROR);
	s->north = ft_strdup(split[1]);
	return (s);
}

t_info		*set_south_texture(char **split, t_info *s)
{
	if (ft_wordcount(split) != 2)
		ft_error(ARGS_IN_FILE_ERROR);
	s->south = ft_strdup(split[1]);
	return (s);
}

t_info		*set_west_texture(char **split, t_info *s)
{
	if (ft_wordcount(split) != 2)
		ft_error(ARGS_IN_FILE_ERROR);
	s->west = ft_strdup(split[1]);
	return (s);
}

t_info		*set_east_texture(char **split, t_info *s)
{
	if (ft_wordcount(split) != 2)
		ft_error(ARGS_IN_FILE_ERROR);
	s->east = ft_strdup(split[1]);
	return (s);
}

t_info		*set_sprite_texture(char **split, t_info *s)
{
	if (ft_wordcount(split) != 2)
		ft_error(ARGS_IN_FILE_ERROR);
	s->sprite = ft_strdup(split[1]);
	return (s);
}
