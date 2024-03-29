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

t_pos	get_iso(t_pos pos, double angle)
{
	t_pos	iso;

	iso.x = (pos.x - pos.y) * angle;
	iso.y = (pos.x + pos.y) / 2 * angle;
	return (iso);
}

t_pos	get_cart(t_pos iso, double angle)
{
	t_pos	cart;

	cart.x = (2 * (iso.y / angle) + (iso.x / angle)) / 2;
	cart.y = (2 * (iso.y / angle) - (iso.x / angle)) / 2;
	return (cart);
}
