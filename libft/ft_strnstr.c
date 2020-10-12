/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:07:00 by flolefeb          #+#    #+#             */
/*   Updated: 2019/11/26 14:44:41 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*find == '\0')
		return ((char*)str);
	if (*str == 0 || len == 0)
		return (NULL);
	while (str[i] && i + j < len)
	{
		j = 0;
		while (find[j] == str[i + j] && i + j < len)
		{
			if (find[j + 1] == '\0')
				return ((char*)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
