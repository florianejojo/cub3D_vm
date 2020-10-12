/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <flolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:45:27 by flolefeb          #+#    #+#             */
/*   Updated: 2020/10/13 00:13:10 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		line_closed(int i, char *line, t_env *env)
{
	int j;

	j = skip_wsp(i, 0, env);
	if (!line)
		return (SUCCESS);
	if (line[j] != '1')
		return (LINE_NOT_CLOSED);
	j = ft_strlen(line) - 1;
	j = skip_wsp_revers(i, j, env);
	if (line[j] != '1')
		return (LINE_NOT_CLOSED);
	return (SUCCESS);
}

int		check_char(int i, int j, t_env *env)
{
	if (is_wsp(i, j, env) == 1)
		env->t_map.map[i][j] = '1';
	if (ft_charset("NSWE", env->t_map.map[i][j]) == 1)
	{
		if (env->t_map.player_dir == 0)
		{
			env->t_map.player_dir = env->t_map.map[i][j];
			env->t_map.player_pos.x = j + 0.5;
			env->t_map.player_pos.y = i + 0.5;
			env->t_map.map[i][j] = '0';
		}
		else
			return (TO_MANY_PLAYER_POS);
	}
	if (ft_charset("012", env->t_map.map[i][j]) != 1
		&& is_wsp(i, j, env) != 1)
		return (WRONG_CHAR);
	if (env->t_map.map[i][j] != '1'
		&& (env->t_map.map[i][j] == '2' || env->t_map.map[i][j] == '0'))
	{
		printf("find_wall_up(env, %d, %d) = %d\n", i, j, find_wall_up(env, i, j));
		if (find_wall_down(env, i, j) != 1 || find_wall_up(env, i, j) != 1)
		{
			printf ("ici\n");
			return (MAP_NOT_CLOSED);
		}
	}
	return (SUCCESS);
}
