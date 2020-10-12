/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <flolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:05:40 by flolefeb          #+#    #+#             */
/*   Updated: 2020/10/12 14:50:19 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_count_words(char *s, char c)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 1;
	while (s[i])
	{
		if (s[i] == c)
			nb_words++;
		i++;
	}
	return (nb_words);
}

static char	**ft_cpy(char **s2, char *s, char c, int nb_words)
{
	int i;
	int j;
	int x;

	i = 0;
	x = 0;
	j = 0;
	while (s[i] && x < nb_words)
	{
		if (s[i] != c)
		{
			j++;
		}
		else if (s[i] == c)
		{
			s2[x] = ft_substr(s, (i - j), j);
			x++;
			j = 0;
		}
		i++;
	}
	s2[x] = ft_substr(s, (i - j), j);
	return (s2);
}

char		**ft_split_cub(t_env *env, char const *s, char c)
{
	char	**s2;
	int		nb_words;

	if (s == NULL)
		return (NULL);
	nb_words = ft_count_words((char*)s, c);
	env->t_map.nb_lines = nb_words;
	if (!(s2 = (char **)malloc(sizeof(char*) * (nb_words + 1))))
		return (NULL);
	s2[nb_words] = 0;
	s2 = ft_cpy(s2, (char *)s, c, nb_words);
	return (s2);
}
