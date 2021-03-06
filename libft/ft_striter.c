/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:47:05 by tdagai            #+#    #+#             */
/*   Updated: 2020/02/24 19:51:26 by tdagai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int		ctr;
	char	*str;

	if (s && f)
	{
		ctr = 0;
		str = s;
		while (str[ctr])
			(*f)(&str[ctr++]);
	}
}
