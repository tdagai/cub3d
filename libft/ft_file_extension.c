/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_extension.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 14:52:22 by teva              #+#    #+#             */
/*   Updated: 2020/10/18 23:33:32 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_file_extension(const char *filename, const char *file_extension)
{
	int		equal_if_zero;
	char	*search;

	equal_if_zero = 1;
	search = ft_strchr(filename, file_extension[0]);
	if (search != NULL)
	{
		if (search[1] == '/')
		{
			search++;
			search = ft_strchr(search, file_extension[0]);
		}
		equal_if_zero = ft_strcmp(search, file_extension);
		if (equal_if_zero == 0)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
