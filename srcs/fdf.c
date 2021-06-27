#include "../inc/fdf.h"

int	deal_key(int key, void *params)
{
	(void)params;
	if (key == ESC_LNX)
		exit_fdf();
	return (0);
}

void	exit_fdf(void)
{
	exit(0);
}

void	ft_fdf(t_var *var, t_data *mlx)
{
	init_display(var, *mlx);
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
	t_var	var;

	ft_bzero(&var, sizeof(t_var));
	if (parsing(&var, ac, av[1]))
	{
		mlx.mlx = mlx_init();
		mlx_get_screen_size(mlx.mlx, &mlx.width, &mlx.height);
		mlx.width *= 0.5;
		mlx.height *= 0.7;
		mlx.win = mlx_new_window(mlx.mlx, mlx.width, mlx.height, "Fdf");
		mlx.img = mlx_new_image(mlx.mlx, mlx.width, mlx.height);
		mlx.addr = (int *)mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel,
				&mlx.line_length, &mlx.endian);
		printf("nb_l = %d  nb_c = %d\n", var.nb_l, var.nb_c);
		ft_fdf(&var, &mlx);
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
		mlx_hook(mlx.win, 17, 0, exit_fdf, (void *)0);
		mlx_key_hook(mlx.win, deal_key, (void *)0);
		mlx_loop(mlx.mlx);
	}
	exit_fdf();
	return (0);
}
