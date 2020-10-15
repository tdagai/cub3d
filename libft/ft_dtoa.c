/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 13:57:06 by teva              #+#    #+#             */
/*   Updated: 2020/07/17 11:41:41 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_doublemod(long double x, long double y)
{
	x = x < 0 ? x * -1 : x;
	y = y < 0 ? y * -1 : y;
	return (x - (unsigned long long int)(x / y) * y);
}

int			ft_round_half_to_even(long double dbl, int prec)
{
	size_t is_even;
	size_t is_half;

	dbl = ft_doublemod(dbl * ft_pow(10, prec), 2);
	is_even = ((int)dbl == 0);
	if (is_even)
	{
		is_half = (dbl >= 0.49 && dbl <= 0.5);
		if (is_half)
			return (1);
	}
	return (0);
}

long double	ft_dtoa_round(long double dbl, int prec)
{
	size_t half_to_even;

	half_to_even = ft_round_half_to_even(dbl, prec);
	if (half_to_even)
		;
	else if (dbl > 0)
		dbl = dbl + (ft_pow(10, (prec * -1) - 1) * 5.0);
	else
		dbl = dbl - (ft_pow(10, (prec * -1) - 1) * 5.0);
	return (dbl);
}

char		*ft_dtoa(long double dbl, size_t prec, size_t base)
{
	long double	nb;
	size_t		len;
	char		*str1;
	char		*str2;

	nb = dbl < 0 ? (ft_dtoa_round(dbl, prec) * -1) : ft_dtoa_round(dbl, prec);
	str1 = ft_itoa_base_unsigned((unsigned long long int)nb, base);
	nb = (nb - (unsigned long long int)nb) * ft_pow(base, prec);
	str2 = ft_itoa_base_unsigned(nb, base);
	if ((len = ft_strlen(str2)) < prec)
		while (len++ < prec)
			ft_strappend_change_second("0", &str2);
	if (prec > 0 && prec < (len = ft_strlen(str2)))
		str2 = ft_downsize(str2, prec);
	ft_signbit(dbl) && base == 10 ? ft_strappend_change_second("-", &str1) : 0;
	if (prec > 0 && base == 10)
	{
		ft_strappend_change_first(&str1, ".");
		ft_strappend_change_first(&str1, str2);
	}
	ft_strdel(&str2);
	return (str1);
}
