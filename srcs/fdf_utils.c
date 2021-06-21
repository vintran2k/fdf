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
