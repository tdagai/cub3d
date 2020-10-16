/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdagai <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 14:33:44 by tdagai            #+#    #+#             */
/*   Updated: 2020/10/15 13:09:11 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		ctr;
	int		index;

	if (!s1 || !s2)
		return (NULL);
	if (!(fresh = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	ctr = 0;
	while (s1[ctr])
	{
		fresh[ctr] = s1[ctr];
		ctr++;
	}
	index = 0;
	while (s2[index])
		fresh[ctr++] = s2[index++];
	fresh[ctr] = 0;
	return (fresh);
}

char	*ft_strjoin_gnl(char *s1, char *s2, size_t size)
{
	int		len;
	char	*fresh;
	size_t	ctr;

	len = ft_strlen(s1) + size;
	if (!(fresh = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ctr = 0;
	while (s1 && s1[ctr] != 0)
	{
		fresh[ctr] = s1[ctr];
		ctr++;
	}
	while (s1 && *s2 != 0)
		fresh[ctr++] = *s2++;
	fresh[ctr] = 0;
	return (fresh);
}
