#include "../inc/fdf.h"

int	deal_key(int key, void *params)
{
	(void)params;
	if (key == ESC_LNX)
		exit(0);
	return (0);
}

int	deal_mouse(void)
{
	exit(0);
	return (0);
}

void	put_pixel(t_data *mlx, int x, int y, int color)
{
	mlx->addr[y * mlx->line_length / 4 + x] = color;
}

/*
void	draw_line_s(t_data *mlx, int x1, int y1, int x2, int y2, int color)
{
	int dx;
	int dy;
	int s;
	int i;
	int j;

	dx = x1 - x2;
	dy = y2 - y1;
	if (dx >= dy)
		s = 2 * dy - dx;
	else
		s = 2 * dx - dy;
	i = x1;
	j = y1;
	while (i > x2)
	{
		if (s < 0)
		{
			if (dx >= dy)
				s = s + 2 * dy;
			else
				s = s + 2 * dx;
		}
		else
		{
			j++;
			if (dx >= dy)
				s = s + 2 * (dy - dx);
			else
				s = s + 2 * (dx - dy);
		}
		put_pixel(mlx, i, j, color);
		i--;
	}
}*/

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

t_pos	get_iso(t_var var, t_pos pos)
{
	t_pos iso;

	iso.x = (pos.x - pos.y) * cos(var.angle); //* cos(var.angle);
	iso.y = (pos.x + pos.y) / 2 * sin(var.angle);// - (var.map[var.y][var.x]);//* sin(var.angle) - (var.map[var.y][var.x + 1]);
	return (iso);
}

void	draw_r(t_var *var, t_data *mlx)
{
	t_pos pos1;
	t_pos pos2;
	t_pos iso1;
	t_pos iso2;

	//init display
	var->startx = HEIGHT / 2;
	var->starty = -150;
	var->size = 40;
	var->angle = 0.67;

	//init normal pos
	pos1.x = var->startx + var->x * var->size;
	pos1.y = var->starty + var->y * var->size;
	pos2.x = var->startx + (var->x + 1) * var->size;
	pos2.y = pos1.y;

	//init iso pos
	iso1 = get_iso(*var, pos1);
	iso2 = get_iso(*var, pos2);
	iso1.y -= var->map[var->y][var->x] * var->angle;
	iso2.y -= var->map[var->y][var->x + 1] * var->angle;
	//iso1.x -= var->map[var->y][var->x] * var->angle;
	//iso2.x -= var->map[var->y][var->x + 1] * var->angle;

	printf("pos1.x = %d  pos1.y = %d  pos2.x = %d  pos2.y = %d\n", pos1.x, pos1.y, pos2.x, pos2.y);
	printf("iso1.x = %d  iso1.y = %d  iso2.x = %d  iso2.y = %d\n", iso1.x, iso1.y, iso2.x, iso2.y);

	//draw line
	draw_line(mlx, iso1.x, iso1.y, iso2.x, iso2.y, 0x00007700);
}

void	draw_d(t_var *var, t_data *mlx)
{
	t_pos pos1;
	t_pos pos2;
	t_pos iso1;
	t_pos iso2;

	//init display
	var->startx = HEIGHT / 2;
	var->starty = -150;
	var->size = 40;
	var->angle = 0.67;

	//init normal pos
	pos1.x = var->startx + var->x * var->size;
	pos1.y = var->starty + var->y * var->size;
	pos2.x = pos1.x;
	pos2.y = var->starty + (var->y + 1) * var->size;

	//init iso pos
	iso1 = get_iso(*var, pos1);
	iso2 = get_iso(*var, pos2);
	iso1.y -= var->map[var->y][var->x] * var->angle;
	iso2.y -= var->map[var->y + 1][var->x] * var->angle;
	//iso1.x -= var->map[var->y][var->x] * var->angle;
	//iso2.x -= var->map[var->y + 1][var->x] * var->angle;

	printf("pos1.x = %d  pos1.y = %d  pos2.x = %d  pos2.y = %d\n", pos1.x, pos1.y, pos2.x, pos2.y);
	printf("iso1.x = %d  iso1.y = %d  iso2.x = %d  iso2.y = %d\n", iso1.x, iso1.y, iso2.x, iso2.y);

	//draw line
	draw_line(mlx, iso1.x, iso1.y, iso2.x, iso2.y, 0x00007700);
}

void	ft_fdf(t_var *var, t_data *mlx)
{
	var->y = 0;
	while (var->y < var->nb_l)
	{
		var->x = 0;
		while (var->x < var->nb_c - 1)
		{
			draw_r(var, mlx);
			var->x++;
		}
		var->y++;
	}
	var->x = 0;
	while (var->x < var->nb_c)
	{
		var->y = 0;
		while (var->y < var->nb_l - 1)
		{
			draw_d(var, mlx);
			var->y++;
		}
		var->x++;
	}
}

int	main(int ac, char **av)
{
	t_data	mlx;
	t_var var;

	ft_bzero(&var, sizeof(t_var));
	if (ac == 2 && parsing(&var, av[1]))
	{
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Fdf");
		mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
		mlx.addr = (int *)mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
				&mlx.endian);
		ft_fdf(&var, &mlx);
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
		mlx_hook(mlx.win, 17, 0, deal_mouse, (void *)0);
		mlx_key_hook(mlx.win, deal_key, (void *)0);
		mlx_loop(mlx.mlx);
	}
}
