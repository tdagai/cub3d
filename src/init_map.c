/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:02:12 by teva              #+#    #+#             */
/*   Updated: 2020/10/20 01:34:07 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**init_map(int len, int wid, char fill)
{
	int		ctr;
	int		i;
	char	**map;

	if (len < 1 || wid < 1)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * len);
	ctr = 0;
	while (ctr < len)
	{
		map[ctr] = (char *)malloc(sizeof(char) * wid);
		i = 0;
		while (i < wid)
			map[ctr][i++] = fill;
		ctr++;
	}
	return (map);
}
