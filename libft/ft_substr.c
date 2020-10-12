/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <flolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 09:40:14 by flolefeb          #+#    #+#             */
/*   Updated: 2020/10/12 15:23:40 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (!(s2 = (char *)malloc(sizeof(size_t) * (len + 1))))
		return (NULL);
	while (s[i] && i < start)
		i++;
	while (s[i] && start < (len + i))
	{
		s2[j] = s[start];
		j++;
		start++;
	}
	s2[j] = '\0';
	return (s2);
}
