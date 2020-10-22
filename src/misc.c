/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:37:02 by teva              #+#    #+#             */
/*   Updated: 2020/10/21 18:57:05 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(int error_num)
{
	ft_putstr_fd("Error\n", 2);
	if (error_num == ARG_ERROR)
		ft_putstr_fd("Invalid number of arguments.\n", 2);
	else if (error_num == FILE_OPEN_ERROR)
		ft_putstr_fd("File did not open properly.\n", 2);
	else if (error_num == FILE_CLOSE_ERROR)
		ft_putstr_fd("File did not close properly.\n", 2);
	else if (error_num == ARGS_IN_FILE_ERROR)
		ft_putstr_fd("Wrong number of arguments in file.\n", 2);
	else if (error_num == TYPE_IDENTIFIER_ERROR)
		ft_putstr_fd("Invalid type identifier.\n", 2);
	else if (error_num == READ_ERROR)
		ft_putstr_fd("There was an error while reading from file.\n", 2);
	else if (error_num == FILE_EXTENSION_ERROR)
		ft_putstr_fd("Wrong file extension.\n", 2);
	else if (error_num == MAP_ERROR)
		ft_putstr_fd("There was an error loading the map.\n", 2);
	exit(1);
}

int			ok_letters(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}
