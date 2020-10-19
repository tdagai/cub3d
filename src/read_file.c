/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:22:31 by teva              #+#    #+#             */
/*   Updated: 2020/10/18 14:51:15 by teva             ###   ########.fr       */
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

t_info		*set_resolution(char **split, t_info *s)
{
	if (ft_wordcount(split) != 3)
		ft_error(ARGS_IN_FILE_ERROR);
	s->res.x = ft_atoi(split[1]);
	s->res.y = ft_atoi(split[2]);
	return (s);
}

t_info		*manage_file_data(char **split, t_info *s)
{
	if (split != NULL && ft_strcmp(split[0], "R") == 0)
		s = set_resolution(split, s);
	else if (split != NULL && ft_strcmp(split[0], "NO") == 0)
		s = set_north_texture(split, s);
	else if (split != NULL && ft_strcmp(split[0], "SO") == 0)
		s = set_south_texture(split, s);
	else if (split != NULL && ft_strcmp(split[0], "WE") == 0)
		s = set_west_texture(split, s);
	else if (split != NULL && ft_strcmp(split[0], "EA") == 0)
		s = set_east_texture(split, s);
	else if (split != NULL && ft_strcmp(split[0], "S") == 0)
		s = set_sprite_texture(split, s);
	else
		ft_error(TYPE_IDENTIFIER_ERROR);
	return (s);
}

t_info		*read_cub_file(char *filename, t_info *s)
{
	int		fd;
	int		gnl_error;
	char	*line;
	char	**split;

	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error(FILE_OPEN_ERROR);
	while ((gnl_error = get_next_line(fd, &line)) != 0)
	{
		gnl_error == -1 ? ft_error(READ_ERROR) : 0;
		split = ft_strsplit(line, ' ');
		if (split[0] == NULL)
			continue;
		s = manage_file_data(split, s);
	}
	close(fd) == -1 ? ft_error(FILE_CLOSE_ERROR) : 0;
	free_split(split);
	ft_memdel((void **)&line);
	return (s);
}
