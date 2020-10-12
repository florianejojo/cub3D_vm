/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:49:46 by flolefeb          #+#    #+#             */
/*   Updated: 2019/11/26 16:18:42 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_charset(char const *set, char c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_end(char const *s1, char const *set, int start)
{
	int i;

	i = ft_strlen(s1) - 1;
	while (i > start && s1[i] && ft_check_charset(set, s1[i]) == 1)
		i--;
	return (i);
}

static int	ft_start(char const *s1, char const *set)
{
	int i;

	i = 0;
	while (s1[i] && ft_check_charset(set, s1[i]) == 1)
		i++;
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		end;
	int		start;
	int		len;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set, start);
	if (start == (end + 1))
		len = 0;
	else
		len = ft_strlen(s1) + 1 - (ft_strlen(s1) - end) - start;
	s2 = ft_substr(s1, start, len);
	return (s2);
}
