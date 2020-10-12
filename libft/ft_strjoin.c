/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:52:27 by flolefeb          #+#    #+#             */
/*   Updated: 2019/11/19 14:53:52 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	k;
	char			*s3;

	i = 0;
	k = 0;
	if (!s1 || !s2 || !(s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
						ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i] && k < (unsigned int)ft_strlen(s1))
		s3[k++] = s1[i++];
	i = 0;
	while (s2[i] && k < (unsigned int)(ft_strlen(s2) + ft_strlen(s1)))
		s3[k++] = s2[i++];
	s3[k] = '\0';
	return (s3);
}
