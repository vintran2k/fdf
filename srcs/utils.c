#include "../inc/fdf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = s;
	i = -1;
	while (++i < n)
	{
		str[i] = 0;
	}
	s = str;
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_getnbr(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		res *= -1;
	return (res);
}

void	init_display(t_var *var)
{
	int sizex, sizey;

	t_pos cart, iso;

	iso.x = var->mlx.width / 2;
	iso.y = var->mlx.height / 2;
	var->angle = 0.1;
	cart = get_cart(iso, var->angle);

	sizex = var->mlx.width / (var->nb_c * 2);
	sizey = var->mlx.height / (var->nb_l * 2);
	var->size = sizex >= sizey ? sizey : sizex;
	var->startx = cart.x - var->nb_c / 2 * var->size;
	var->starty = cart.y - var->nb_l / 2 * var->size;
}
