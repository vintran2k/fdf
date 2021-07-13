#include "../inc/fdf.h"

int	deal_key(int key, t_var *var)
{
	if (key == ESC_LNX)
		exit_fdf(var);
	return (0);
}

void	init_display(t_var *var)
{
	int		sizex;
	int		sizey;
	t_pos	cart;
	t_pos	iso;

	iso.x = var->mlx.width / 2;
	iso.y = var->mlx.height / 2;
	cart = get_cart(iso, var->angle);
	sizex = var->mlx.width / (var->nb_c * 2);
	sizey = var->mlx.height / (var->nb_l * 2);
	var->size = sizex;
	if (sizex >= sizey)
		var->size = sizey;
	var->startx = cart.x - var->nb_c / 2 * var->size;
	var->starty = cart.y - var->nb_l / 2 * var->size;
}

void	ft_fdf(t_var *var)
{
	init_display(var);
	var->y = 0;
	while (var->y < var->nb_l)
	{
		var->x = 0;
		while (var->x < var->nb_c - 1)
		{
			draw_r(var);
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
			draw_d(var);
			var->y++;
		}
		var->x++;
	}
}

int	main(int ac, char **av)
{
	t_var	var;

	ft_bzero(&var, sizeof(t_var));
	var.angle = 1;
	var.alt = 1;
	if (parsing(&var, ac, av[1]))
	{
		var.mlx.mlx = mlx_init();
		mlx_get_screen_size(var.mlx.mlx, &var.mlx.width, &var.mlx.height);
		var.mlx.width *= 0.5;
		var.mlx.height *= 0.7;
		var.mlx.win
			= mlx_new_window(var.mlx.mlx, var.mlx.width, var.mlx.height, "Fdf");
		var.mlx.img = mlx_new_image(var.mlx.mlx, var.mlx.width, var.mlx.height);
		var.mlx.addr
			= (int *)mlx_get_data_addr(var.mlx.img, &var.mlx.bits_per_pixel,
				&var.mlx.line_length, &var.mlx.endian);
		ft_fdf(&var);
		mlx_put_image_to_window(var.mlx.mlx, var.mlx.win, var.mlx.img, 0, 0);
		mlx_hook(var.mlx.win, 17, 0, exit_fdf, &var);
		mlx_key_hook(var.mlx.win, deal_key, &var);
		mlx_loop(var.mlx.mlx);
	}
	exit_fdf(&var);
	return (0);
}
