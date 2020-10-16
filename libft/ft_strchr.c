/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:43:34 by tdagai            #+#    #+#             */
/*   Updated: 2020/10/15 13:12:36 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		ctr;

	ctr = 0;
	while (str[ctr] && str[ctr] != c)
		ctr++;
	if (str[ctr] == c)
		return ((char *)(str + ctr));
	else
		return (NULL);
}

int		ft_strchr_gnl(const char *str, int c)
{
	int		ctr;

	ctr = 0;
	while (str[ctr])
	{
		if (str[ctr] == c)
			return (ctr);
		ctr++;
	}
	return (-1);
}
