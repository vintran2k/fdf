#ifndef FDF_H
# define FDF_H
# define ESC_MAC 53
# define ESC_LNX 65307
# define WIDTH 1900
# define HEIGHT 1080
# define BUFFER_SIZE 4096

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	//int			width;
	//int			height;
}				t_data;

typedef struct	s_var
{
	int nb_l;
	int nb_c;
	char *file;
	int **map;
	int	x;
	int	y;
	int size;
	int startx;
	int starty;
	double angle;
}				t_var;

typedef struct	s_pos
{
	float	x;
	float	y;
}				t_pos;

void	put_pixel(t_data *data, int x, int y, int color);
void	ft_putnbr(long nb);
int		ft_getnbr(char *str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_bzero(void *s, size_t n);
char	*ft_sstrndup(char *src, int n);
int		is_newline(char *s);
int		ft_sstrlen(char *str);
void	ft_free_tab(char **tab, size_t size);
int		deal_key(int key, void *params);
int		deal_mouse(void);
char	**ft_split(const char *s, char c);
int		get_next_line(int fd, char **line, char **file);
int		parsing(t_var *var, char *map);

// mlx.addr = (int *)mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
// mlx.addr[y * mlx.line_length / 4 + x] = color;

#endif
