#include "fdf_bonus.h"

int	key_press_bonus(int key, t_var *var)
{
	if (key == ESC_LNX)
		exit_fdf(var);
	if (key == ARROW_UP)
		var->up = 1;
	if (key == ARROW_DOWN)
		var->down = 1;
	return (0);
}

int	key_release_bonus(int key, t_var *var)
{
	if (key == ARROW_UP)
		var->up = 0;
	if (key == ARROW_DOWN)
		var->down = 0;
	return (0);
}

void	clean_img(t_var *var)
{
	mlx_destroy_image(var->mlx.mlx, var->mlx.img);
	var->mlx.img = mlx_new_image(var->mlx.mlx, var->mlx.width, var->mlx.height);
	var->mlx.addr = (int *)mlx_get_data_addr(var->mlx.img, &var->mlx.bits_per_pixel,
				&var->mlx.line_length, &var->mlx.endian);
}

void	init_display_bonus(t_var *var)
{
	int sizex;
	int sizey;
	t_pos cart;
	t_pos iso;

	iso.x = var->mlx.width / 2;
	iso.y = var->mlx.height / 2;
	if (var->up == 1)
		var->angle *= 1.005;
	if (var->down == 1)
		var->angle *= 0.995;
	cart = get_cart(iso, var->angle);
	sizex = var->mlx.width / (var->nb_c * 2);
	sizey = var->mlx.height / (var->nb_l * 2);
	var->size = sizex >= sizey ? sizey : sizex;
	var->startx = cart.x - var->nb_c / 2 * var->size;
	var->starty = cart.y - var->nb_l / 2 * var->size;
}
