NAME			=	fdf
MLX_DIR			=	./minilibx-linux/
INC_DIR			=	./inc/
SRCS_DIR		=	./srcs/
SRCS			=	fdf.c					\
					utils.c					\
					parsing.c				\
					draw.c					\
					ft_split.c				\
					get_next_line.c			\
					get_next_line_utils.c
SRCS_BASENAME	=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJS			=	$(SRCS_BASENAME:.c=.o)
CC				=	gcc
FLAGS			=	-Wall -Wextra -g -I $(INC_DIR) -I $(MLX_DIR) # -Werror

.c.o		:
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			make -C $(MLX_DIR)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
			@echo [$(NAME)] : Created !

clean		:
			rm -rf $(OBJS)
			make clean -C $(MLX_DIR)
			@echo "[OBJS] Deleted"

fclean		:	clean
			rm -f $(NAME)
			@echo "[$(NAME)]: Deleted"

re			:	fclean all