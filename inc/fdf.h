#ifndef FDF_H
# define FDF_H
# define ESC_LNX 65307
# define BUFFER_SIZE 4096

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	float		dx;
	float		dy;
	float		error;
}				t_data;

typedef struct s_var
{
	t_data	mlx;
	int		fd;
	int		ret;
	int		nb_l;
	int		nb_c;
	char	*file;
	char	*line;
	int		**map;
	int		x;
	int		y;
	int		size;
	int		startx;
	int		starty;
	double	angle;
	double	alt;
	int		up;
	int		down;
	int		left;
	int		right;
}				t_var;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

void	put_pixel(t_data *data, int x, int y, int color);
void	draw_line(t_data *mlx, t_pos pos1, t_pos pos2, int color);
void	draw_r(t_var *var);
void	draw_d(t_var *var);
t_pos	get_iso(t_pos pos, double angle);
t_pos	get_cart(t_pos iso, double angle);
void	init_display(t_var *var);
int		ft_getnbr(char *str);
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
char	*ft_sstrndup(char *src, int n);
int		is_newline(char *s);
int		ft_sstrlen(char *str);
size_t	ft_count_words(const char *s, char c);
void	ft_free_tab(char **tab, size_t size);
int		deal_key(int key, t_var *var);
int		exit_fdf(t_var *var);
char	**ft_split(const char *s, char c);
int		get_next_line(int fd, char **line, char **file, int ret);
int		parsing(t_var *var, int ac, char *map);

#endif
