/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 02:46:34 by vintran           #+#    #+#             */
/*   Updated: 2021/07/13 18:12:11 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	put_pixel(t_data *mlx, int x, int y, int color)
{
	if ((x >= 0 && x < mlx->width) && (y >= 0 && y < mlx->height))
		mlx->addr[y * mlx->line_length / 4 + x] = color;
}

void	draw_line(t_data *mlx, int x1, int y1, int x2, int y2, int color)
{
	t_pos	delta;
	t_pos	sign;
	t_pos	cur;
	int		error[2];

	delta.x = abs(x2 - x1);
	delta.y = abs(y2 - y1);
	sign.x = x1 < x2 ? 1 : -1;
	sign.y = y1 < y2 ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur.x = x1;
	cur.y = y1;
	while (cur.x != x2 || cur.y != y2)
	{
		put_pixel(mlx, cur.x, cur.y, color);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
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
	//draw_line(&var->mlx, iso1.x, iso1.y, iso2.x, iso2.y, 0x00007700);
	draw_line_s(&var->mlx, iso1, iso2, 0x00007700);
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
	//draw_line(&var->mlx, iso1.x, iso1.y, iso2.x, iso2.y, 0x00007700);
	draw_line_s(&var->mlx, iso1, iso2, 0x00007700);
}
