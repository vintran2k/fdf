#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363

# include "../../inc/fdf.h" 

int		key_press_bonus(int key, t_var *var);
int		key_release_bonus(int key, t_var *var);
void	init_display_bonus(t_var *var);
void	clean_img(t_var *var);

#endif
