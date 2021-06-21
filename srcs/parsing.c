/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:00:58 by vintran           #+#    #+#             */
/*   Updated: 2021/06/21 17:44:27 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	malloc_map(t_var *var)
{
	int i;

	i = 0;
	var->map = malloc(sizeof(int *) * var->nb_l);
	if (!var->map)
		return (0);
	while (i < var->nb_l)
	{
		var->map[i] = malloc(sizeof(int) * var->nb_c);
		if (!var->map[i])
			return (0);
		i++;
	}
	return (1);
}

int	fill_map_line(t_var *var, char **split, int map_line)
{
	int i;
	int j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (split[i][j] < '0' || split[i][j] > '9')
				return (0);
			j++;
		}
		var->map[map_line][i] = ft_getnbr(split[i]);
		i++;
	}
	return (1);
}

int	get_map(char *map, t_var *var)
{
	int fd;
	int map_line;
	char *line;
	char **split;
	int ret;

	map_line = 0;
	var->file = NULL;
	ret = 1;
	if ((fd = open(map, O_RDONLY)) == -1)
		return (0);
	while (ret)
	{
		ret = get_next_line(fd, &line, &var->file);
		split = ft_split(line, ' ');
		if (!fill_map_line(var, split, map_line))
		{
			free(line);
			free(var->file);
			return (0);
		}
		free(line);
		map_line++;
		ft_free_tab(split, var->nb_c);
	}
	close(fd);
	return (1);
}

int		parsing(t_var *var, char *map)
{
	int fd;
	char *line;
	int i;
	int ret;

	if ((fd = open(map, O_RDONLY)) == -1)
		return (0);
	ret = 1;
	while(ret)
	{
		ret = get_next_line(fd, &line, &var->file);
		if (var->nb_l == 0)
		{
			i = 0;
			while (line[i])
			{
				if (line[i] != ' ')
					var->nb_c++;
				i++;
			}
		}
		free(line);
		var->nb_l++;
	}
	close(fd);
	if (!malloc_map(var) || !get_map(map, var))
		return (0);
	return (1);
}

