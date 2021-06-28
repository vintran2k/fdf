/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 15:00:58 by vintran           #+#    #+#             */
/*   Updated: 2021/06/28 03:53:14 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	malloc_map(t_var *var)
{
	int	i;

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

void	get_map(char *map, t_var *var)
{
	int		fd;
	int		i;
	int		j;
	char	**split;
	int		ret;

	i = 0;
	var->file = NULL;
	ret = 1;
	fd = open(map, O_RDONLY);
	while (ret)
	{
		ret = get_next_line(fd, &var->line, &var->file);
		split = ft_split(var->line, ' ');
		j = 0;
		while (split[j])
		{
			var->map[i][j] = ft_getnbr(split[j]);
			j++;
		}
		free(var->line);
		var->line = NULL;
		i++;
		ft_free_tab(split, var->nb_c);
	}
	close(fd);
}

int	get_map_size(t_var *var, char *map)
{
	int		ret;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (0);
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &var->line, &var->file);
		if (!var->nb_c)
			var->nb_c = (int)ft_count_words(var->line, ' ');
		else
		{
			if ((int)ft_count_words(var->line, ' ') != var->nb_c)
				return (0);
		}
		free(var->line);
		var->line = NULL;
		var->nb_l++;
	}
	if (close(fd) == -1)
		return (0);
	return (1);
}

int	parsing(t_var *var, int ac, char *map)
{
	int		ret;

	ret = 1;
	if (ac != 2)
	{
		printf("Error\nToo few arguments\n");
		return (0);
	}
	if (!get_map_size(var, map))
	{
		printf("Error\nInvalid file\n");
		return (0);
	}
	if (!malloc_map(var))
	{
		printf("Error\nMalloc failled\n");
		return (0);
	}
	get_map(map, var);
	return (1);
}
