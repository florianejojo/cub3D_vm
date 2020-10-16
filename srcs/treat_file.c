/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flolefeb <flolefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 14:05:43 by flolefeb          #+#    #+#             */
/*   Updated: 2020/10/13 16:17:35 by flolefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		check_file(char *file)
{
	int		len;

	len = ft_strlen(file) - 1;
	if (file[len] != 'b')
		return (INVALID_FILE);
	if (file[len - 1] != 'u')
		return (INVALID_FILE);
	if (file[len - 2] != 'c')
		return (INVALID_FILE);
	if (file[len - 3] != '.')
		return (INVALID_FILE);
	return (SUCCESS);
}

int		make_map(char *file, t_env *env)
{
	int		fd;
	int		ret;
	char	buf[2];
	char	*str;
	int		i;

	i = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (FILE_NOT_OPENED);
	while ((ret = read(fd, buf, 1)) > 0)
		env->t_map.nb_char++;
	if (!(str = (char *)malloc(sizeof(char) * (env->t_map.nb_char + 1))))
		return (MALLOC_FAILED);
	close(fd);
	if ((fd = open(file, O_RDONLY)) < 0)
		return (FILE_NOT_OPENED);
	while ((ret = read(fd, buf, 1)) > 0)
		str[i++] = buf[0];
	str[i] = '\0';
	env->t_map.map = ft_split_cub(env, str, '\n');
	close(fd);
	if (str)
		free(str);
	return (SUCCESS);
}

int		treat_file(char *file, t_env *env)
{
	if ((env->error = check_file(file)) != SUCCESS)
		return (env->error);
	else if ((env->error = make_map(file, env)) != SUCCESS)
		return (env->error);
	else if ((env->error = check_map(env)) != SUCCESS)
		return (env->error);
	else if ((env->error = pars_map(env)) != SUCCESS)
		return (env->error);
	fill_spaces(env);
	return (SUCCESS);
}
