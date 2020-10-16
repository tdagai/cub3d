/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:06:32 by tdagai            #+#    #+#             */
/*   Updated: 2020/10/15 13:14:04 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		save_space(char **line, char **cache, int endl_pos)
{
	char *temp;

	if (endl_pos >= 0)
	{
		if (!(*line = ft_substr(*cache, 0, endl_pos)))
			return (-1);
		if (!(temp = ft_substr(*cache, endl_pos + 1,\
					ft_strlen(*cache) - endl_pos - 1)))
			return (-1);
	}
	else
	{
		if (!(*line = ft_substr(*cache, 0, ft_strlen(*cache))))
			return (-1);
		temp = 0;
	}
	ft_memdel_gnl(*cache);
	*cache = temp;
	if (!*cache)
		return (0);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char *cache[MAX_FD];
	ssize_t		b;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;

	if (fd < 0 || !line)
		return (-1);
	if (!cache[fd])
		cache[fd] = ft_strnew_gnl();
	while ((b = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[b] = '\0';
		temp = ft_strjoin_gnl(cache[fd], buf, b);
		ft_memdel_gnl(cache[fd]);
		cache[fd] = temp;
		if (ft_strchr_gnl(cache[fd], '\n') != -1)
			break ;
	}
	if (b < 0)
		return (-1);
	return (save_space(line, &cache[fd], ft_strchr_gnl(cache[fd], '\n')));
}
