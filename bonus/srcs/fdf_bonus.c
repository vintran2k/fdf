#include "fdf_bonus.h"

int	ft_fdf_bonus(t_var *var)
{
	init_display_bonus(var);
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
	mlx_put_image_to_window(var->mlx.mlx, var->mlx.win, var->mlx.img, 0, 0);
	clean_img(var);
	return (0);
}

int	main(int ac, char **av)
{
	t_var	var;

	ft_bzero(&var, sizeof(t_var));
	var.angle = 1;
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
		mlx_hook(var.mlx.win, 17, 0, exit_fdf, &var);
		mlx_hook(var.mlx.win, 02, 1L << 0, key_press_bonus, &var);
		mlx_hook(var.mlx.win, 03, 1L << 1, key_release_bonus, &var);
		mlx_loop_hook(var.mlx.mlx, ft_fdf_bonus, &var);
		mlx_loop(var.mlx.mlx);
	}
	exit_fdf(&var);
	return (0);
}
