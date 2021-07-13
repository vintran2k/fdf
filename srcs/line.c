/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:32:38 by vintran           #+#    #+#             */
/*   Updated: 2021/07/13 19:30:24 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	draw_h_g(t_data *mlx, t_pos pos1, t_pos pos2, int color)
{
	if (mlx->dx > mlx->dy)
	{
		while (pos1.x <= pos2.x)
		{
			put_pixel(mlx, pos1.x++, pos1.y, color);
			mlx->error -= 2 * mlx->dy;
			if (mlx->error < 0)
			{
				pos1.y++;
				mlx->error += 2 * mlx->dx;
			}
		}
		return ;
	}
	while (pos1.y <= pos2.y)
	{
		put_pixel(mlx, pos1.x, pos1.y++, color);
		mlx->error -= 2 * mlx->dx;
		if (mlx->error < 0)
		{
			pos1.x++;
			mlx->error += 2 * mlx->dy;
		}
	}
}

void	draw_b_d(t_data *mlx, t_pos pos1, t_pos pos2, int color)
{
	if (mlx->dx < mlx->dy)
	{
		while (pos1.y >= pos2.y)
		{
			put_pixel(mlx, pos1.x, pos1.y--, color);
			mlx->error -= 2 * mlx->dx;
			if (mlx->error < 0)
			{
				pos1.x--;
				mlx->error += 2 * mlx->dy;
			}
		}
		return ;
	}
	while (pos1.x >= pos2.x)
	{
		put_pixel(mlx, pos1.x--, pos1.y, color);
		mlx->error -= 2 * mlx->dy;
		if (mlx->error < 0)
		{
			pos1.y--;
			mlx->error += 2 * mlx->dx;
		}
	}
}

void	draw_b_g(t_data *mlx, t_pos pos1, t_pos pos2, int color)
{
	if (mlx->dx > mlx->dy)
	{
		while (pos1.x <= pos2.x)
		{
			put_pixel(mlx, pos1.x++, pos1.y, color);
			mlx->error -= 2 * mlx->dy;
			if (mlx->error < 0)
			{
				pos1.y--;
				mlx->error += 2 * mlx->dx;
			}
		}
		return ;
	}
	while (pos1.y >= pos2.y)
	{
		put_pixel(mlx, pos1.x, pos1.y--, color);
		mlx->error -= 2 * mlx->dx;
		if (mlx->error < 0)
		{
			pos1.x++;
			mlx->error += 2 * mlx->dy;
		}
	}
}

void	draw_h_d(t_data *mlx, t_pos pos1, t_pos pos2, int color)
{
	if (mlx->dx > mlx->dy)
	{
		while (pos1.x >= pos2.x)
		{
			put_pixel(mlx, pos1.x--, pos1.y, color);
			mlx->error -= 2 * mlx->dy;
			if (mlx->error < 0)
			{
				pos1.y++;
				mlx->error += 2 * mlx->dx;
			}
		}
		return ;
	}
	while (pos1.y <= pos2.y)
	{
		put_pixel(mlx, pos1.x, pos1.y++, color);
		mlx->error -= 2 * mlx->dx;
		if (mlx->error < 0)
		{
			pos1.x--;
			mlx->error += 2 * mlx->dy;
		}
	}
}

void	draw_line(t_data *mlx, t_pos pos1, t_pos pos2, int color)
{
	mlx->dx = abs(pos2.x - pos1.x);
	mlx->dy = abs(pos2.y - pos1.y);
	mlx->error = 0;
	if (pos1.x <= pos2.x && pos1.y <= pos2.y)
		draw_h_g(mlx, pos1, pos2, color);
	else if (pos1.x >= pos2.x && pos1.y >= pos2.y)
		draw_b_d(mlx, pos1, pos2, color);
	else if (pos1.x <= pos2.x && pos1.y >= pos2.y)
		draw_b_g(mlx, pos1, pos2, color);
	else
		draw_h_d(mlx, pos1, pos2, color);
}
