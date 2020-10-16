/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 12:07:08 by tdagai            #+#    #+#             */
/*   Updated: 2020/10/15 13:00:23 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *fresh;

	if (!(fresh = (char *)malloc(size + 1)))
		return (NULL);
	ft_memset(fresh, 0, size + 1);
	return (fresh);
}

char	*ft_strnew_gnl(void)
{
	char	*fresh;

	if (!(fresh = (char *)malloc(sizeof(char))))
		return (NULL);
	fresh[0] = '\0';
	return (fresh);
}
