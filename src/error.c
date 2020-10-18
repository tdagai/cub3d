/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:37:02 by teva              #+#    #+#             */
/*   Updated: 2020/10/18 00:55:18 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(int error_num)
{
	ft_putstr_fd("Error\n", 2);
	if (error_num == 1)
		ft_putstr_fd("Invalid number of arguments.\n", 2);
	else if (error_num == 2)
		ft_putstr_fd("File did not open properly.\n", 2);
	else if (error_num == 3)
		ft_putstr_fd("File did not close properly.\n", 2);
	else if (error_num == 4)
		ft_putstr_fd("Wrong number of arguments in file.\n", 2);
	else if (error_num == 5)
		ft_putstr_fd("Invalid type identifier.\n", 2);
	else if (error_num == 6)
		ft_putstr_fd("There was an error while reading from file.\n", 2);
	exit(0);
}
