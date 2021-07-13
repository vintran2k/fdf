NAME			=	fdf_bonus
MLX_DIR			=	../minilibx-linux/
INC_DIR			=	./inc/
SRCS_DIR		=	./srcs/
FIRST_SRCS		=	../srcs/
SRCS			=	fdf_bonus.c		\
					utils_bonus.c

SRCS_BASENAME	=	$(addprefix $(SRCS_DIR), $(SRCS))					\
					$(addprefix $(FIRST_SRCS), draw.c)					\
					$(addprefix $(FIRST_SRCS), line.c)					\
					$(addprefix $(FIRST_SRCS), parsing.c)				\
					$(addprefix $(FIRST_SRCS), ft_split.c)				\
					$(addprefix $(FIRST_SRCS), get_next_line.c)			\
					$(addprefix $(FIRST_SRCS), get_next_line_utils.c)	\
					$(addprefix $(FIRST_SRCS), utils.c)					\
					$(addprefix $(FIRST_SRCS), exit.c)
OBJS			=	$(SRCS_BASENAME:.c=.o)
CC				=	clang
FLAGS			=	-Wall -Wextra -Werror -I $(INC_DIR) -I $(MLX_DIR)

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