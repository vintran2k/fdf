/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 18:29:03 by vintran           #+#    #+#             */
/*   Updated: 2021/06/28 03:51:38 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/fdf.h>

void	mlx_destroy(t_var *var)
{
	if (var->mlx.img)
		mlx_destroy_image(var->mlx.mlx, var->mlx.img);
	if (var->mlx.win)
		mlx_destroy_window(var->mlx.mlx, var->mlx.win);
	if (var->mlx.mlx)
	{
		mlx_destroy_display(var->mlx.mlx);
		free(var->mlx.mlx);
	}
}

int	exit_fdf(t_var *var)
{
	int	i;

	i = -1;
	if (var->map)
	{
		while (++i < var->nb_l)
			free(var->map[i]);
		free(var->map);
	}
	if (var->line)
		free(var->line);
	mlx_destroy(var);
	exit(0);
	return (0);
}
