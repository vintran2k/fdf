/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 02:46:34 by vintran           #+#    #+#             */
/*   Updated: 2021/07/13 19:18:43 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	put_pixel(t_data *mlx, int x, int y, int color)
{
	if ((x >= 0 && x < mlx->width) && (y >= 0 && y < mlx->height))
		mlx->addr[y * mlx->line_length / 4 + x] = color;
}

void	draw_r(t_var *var)
{
	t_pos	pos1;
	t_pos	pos2;
	t_pos	iso1;
	t_pos	iso2;

	pos1.x = var->startx + var->x * var->size;
	pos1.y = var->starty + var->y * var->size;
	pos2.x = var->startx + (var->x + 1) * var->size;
	pos2.y = pos1.y;
	iso1 = get_iso(pos1, var->angle);
	iso2 = get_iso(pos2, var->angle);
	iso1.y -= (var->map[var->y][var->x] * var->alt) * 3 * var->angle;
	iso2.y -= (var->map[var->y][var->x + 1] * var->alt) * 3 * var->angle;
	draw_line(&var->mlx, iso1, iso2, 0x00007700);
}

void	draw_d(t_var *var)
{
	t_pos	pos1;
	t_pos	pos2;
	t_pos	iso1;
	t_pos	iso2;

	pos1.x = var->startx + var->x * var->size;
	pos1.y = var->starty + var->y * var->size;
	pos2.x = pos1.x;
	pos2.y = var->starty + (var->y + 1) * var->size;
	iso1 = get_iso(pos1, var->angle);
	iso2 = get_iso(pos2, var->angle);
	iso1.y -= (var->map[var->y][var->x] * var->alt) * 3 * var->angle;
	iso2.y -= (var->map[var->y + 1][var->x] * var->alt) * 3 * var->angle;
	draw_line(&var->mlx, iso1, iso2, 0x00007700);
}
