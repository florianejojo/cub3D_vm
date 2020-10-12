/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:01:16 by flolefeb          #+#    #+#             */
/*   Updated: 2019/11/26 14:37:42 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long int n)
{
	int len;
	int a;

	len = 0;
	a = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		a = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	if (a == 1)
		len++;
	return (len);
}

static char	*ft_fill(int i, int a, char *str, long int nb)
{
	while (i >= a)
	{
		str[i--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nb;
	int			a;
	int			len;

	nb = n;
	i = 0;
	a = 0;
	len = ft_len(nb);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
		a = 1;
	}
	i = (len) - 1;
	str = ft_fill(i, a, str, nb);
	str[len] = '\0';
	return (str);
}
