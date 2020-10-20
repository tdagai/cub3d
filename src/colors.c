/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 10:04:43 by teva              #+#    #+#             */
/*   Updated: 2020/10/19 11:44:11 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_info		*set_color_rgb(char **split, t_info *s, char identifier)
{
	char	**str;

	ft_wordcount(split) != 2 ? ft_error(ARGS_IN_FILE_ERROR) : 0;
	str = ft_strsplit(split[1], ',');
	ft_wordcount(str) != 3 ? ft_error(ARGS_IN_FILE_ERROR) : 0;
	if (identifier == 'C')
	{
		s->ceiling_color[0] = ft_atoi(str[0]);
		s->ceiling_color[1] = ft_atoi(str[1]);
		s->ceiling_color[2] = ft_atoi(str[2]);
	}
	else if (identifier == 'F')
	{
		s->floor_color[0] = ft_atoi(str[0]);
		s->floor_color[1] = ft_atoi(str[1]);
		s->floor_color[2] = ft_atoi(str[2]);
	}
	free_split(str);
	return (s);
}
