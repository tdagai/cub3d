/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:22:31 by teva              #+#    #+#             */
/*   Updated: 2020/10/17 15:28:35 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


/* ************************************ */
/*✓	To Do:								*/
/*	• Check if file ends with ".cub"	*/
/*		- If no, send error				*/
/*		- If yes, proceed				*/
/*	• Read from file					*/
/*	• Return data to main				*/
/* ************************************ */

char	*read_cub_file(char *filename, t_info *s)
{
	int		fd;
	int		ctr;
	char	*line;
	char	**split;

	fd = open(filename, O_RDONLY);
	get_next_line(fd, &line);
	close(fd);
	split = ft_strsplit(line, ' ');
	ctr = 0;
	while (ctr < ft_wordcount(split))
		printf("%s\n", split[ctr++]);

	ctr = 0;
	while (ctr <= ft_wordcount(split))
		free (split[ctr++]);
	free (split);
	return (line);
}
