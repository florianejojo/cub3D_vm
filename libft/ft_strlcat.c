/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:36:23 by flolefeb          #+#    #+#             */
/*   Updated: 2019/11/18 13:33:09 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[l] && l + i + 1 < dstsize)
	{
		dst[i + l] = src[l];
		l++;
	}
	if (i < dstsize)
		dst[i + l] = '\0';
	return (i + ft_strlen(src));
}
