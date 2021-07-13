NAME			=	fdf
BONUS_NAME		=	fdf_bonus
BONUS_DIR		=	./bonus/
MLX_DIR			=	./minilibx-linux/
INC_DIR			=	./inc/
SRCS_DIR		=	./srcs/
SRCS			=	fdf.c					\
					utils.c					\
					parsing.c				\
					draw.c					\
					line.c					\
					ft_split.c				\
					get_next_line.c			\
					get_next_line_utils.c	\
					exit.c
SRCS_BASENAME	=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJS			=	$(SRCS_BASENAME:.c=.o)
CC				=	clang
FLAGS			=	-Wall -Wextra -Werror -I $(INC_DIR) -I $(MLX_DIR)

.c.o			:
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all				:	$(NAME)

bonus			:	$(BONUS_NAME)

$(NAME)			:	$(OBJS)
				make -C $(MLX_DIR)
				$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
				@echo [$(NAME)] : Created !

$(BONUS_NAME)	:
				make -C $(BONUS_DIR)
				mv $(BONUS_DIR)$(BONUS_NAME) ./

clean			:
				rm -rf $(OBJS)
				make clean -C $(MLX_DIR)
				make clean -C $(BONUS_DIR)
				@echo "[OBJS] Deleted"

fclean			:	clean
				rm -f $(NAME)
				rm -f $(BONUS_NAME)
				@echo "[$(NAME)]: Deleted"

re				:	fclean all