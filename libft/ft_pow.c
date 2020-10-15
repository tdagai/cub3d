/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:20:00 by teva              #+#    #+#             */
/*   Updated: 2020/07/08 14:40:23 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_pow(long double dbl, long double pwr)
{
	long double base;

	base = dbl;
	if (pwr > 0)
		while (pwr-- > 1)
			base *= dbl;
	else if (pwr < 0)
		while (pwr++ <= 0)
			base /= dbl;
	else if (pwr == 0)
		base = 1;
	return (base);
}
