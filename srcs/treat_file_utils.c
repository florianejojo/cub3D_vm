/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <flolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:23:57 by flolefeb          #+#    #+#             */
/*   Updated: 2020/10/12 14:50:44 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		skip_wsp(int i, int j, t_env *env)
{
	if (env->t_map.map[i])
	{
		while (env->t_map.map[i][j] && (env->t_map.map[i][j] == ' '
		|| env->t_map.map[i][j] == '\t' || env->t_map.map[i][j] == '\v'
		|| env->t_map.map[i][j] == '\n' || env->t_map.map[i][j] == '\f'
		|| env->t_map.map[i][j] == '\r'))
			j++;
		return (j);
	}
	return (0);
}

int		skip_wsp_revers(int i, int j, t_env *env)
{
	if (env->t_map.map[i])
	{
		while (env->t_map.map[i][j] && (env->t_map.map[i][j] == ' '
		|| env->t_map.map[i][j] == '\t' || env->t_map.map[i][j] == '\v'
		|| env->t_map.map[i][j] == '\n' || env->t_map.map[i][j] == '\f'
		|| env->t_map.map[i][j] == '\r'))
			j--;
		return (j);
	}
	return (0);
}

int		is_wsp(int i, int j, t_env *env)
{
	if (env->t_map.map[i][j] && (env->t_map.map[i][j] == ' '
		|| env->t_map.map[i][j] == '\t' || env->t_map.map[i][j] == '\v'
		|| env->t_map.map[i][j] == '\n' || env->t_map.map[i][j] == '\f'
		|| env->t_map.map[i][j] == '\r'))
		return (1);
	return (0);
}

int		find_wall_up(t_env *env, int i, int j)
{
	i = i - 1;
	while (env->t_map.map[i] && env->t_map.map[i][j] != '1')
		i--;
	if (env->t_map.map[i] && env->t_map.map[i][j] == '1')
		return (1);
	return (0);
}

int		find_wall_down(t_env *env, int i, int j)
{
	while (env->t_map.map[i] && env->t_map.map[i][j] != '1')
		i++;
	if (env->t_map.map[i] && env->t_map.map[i][j] == '1')
		return (1);
	return (0);
}
