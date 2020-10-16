/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <flolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:45:27 by flolefeb          #+#    #+#             */
/*   Updated: 2020/10/16 14:50:49 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	find_end_line(int i, int j, t_env *env)
{
	i = env->t_map.nb_lines - 1;
	while (env->t_map.end_line == 0 && i > env->t_map.start_line)
	{
		if (env->t_map.map[i])
		{
			j = skip_wsp(i, 0, env);
			if (env->t_map.map[i][j])
				env->t_map.end_line = i;
		}
		i--;
	}
}

int		find_start_end_line(t_env *env)
{
	int j;
	int i;

	j = 0;
	i = env->t_map.i;
	while (i < env->t_map.nb_lines && env->t_map.start_line == 0)
	{
		if (env->t_map.map[i])
		{
			j = skip_wsp(i, 0, env);
			if (env->t_map.map[i][j])
				env->t_map.start_line = i;
		}
		i++;
	}
	find_end_line(i, j, env);
	if (env->t_map.start_line == 0 || env->t_map.end_line == 0
		|| env->t_map.i == 0)
		return (ERROR_START_END);
	return (SUCCESS);
}

void	fill_spaces(t_env *env)
{
	int i;
	int j;

	i = env->t_map.start_line;
	j = 0;
	while (env->t_map.map[i] && i <= env->t_map.end_line)
	{
		while (env->t_map.map[i][j])
		{
			if (env->t_map.map[i][j] == ' ')
				env->t_map.map[i][j] = '1';
			j++;
		}
		j = 0;
		i++;
	}
}

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
	if (env->t_map.map[i][j] != '1' && env->t_map.map[i][j] != ' ')
		if (find_wall_down(env, i, j) != 1 || find_wall_up(env, i, j) != 1)
			return (MAP_NOT_CLOSED);
	return (SUCCESS);
}
