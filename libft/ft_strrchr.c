/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:37:56 by flolefeb          #+#    #+#             */
/*   Updated: 2019/11/26 14:45:09 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)s;
	while (str[i])
		i++;
	if (c == 0)
		return (&str[i]);
	while (i > 0)
	{
		i--;
		if (str[i] == c)
			return (&str[i]);
	}
	return ((char*)'\0');
}
