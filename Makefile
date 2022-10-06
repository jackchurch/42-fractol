
FLAGS	= -Wall -Wextra -Werror -O0 -MP -MD

NAME	= fract_ol
MLX_LIB	= libmlx.dylib

MLX_PATH	= ./mlx
SRC_PATH	= ./src
OBJ_PATH	= ./obj
INC_PATH	= ./inc

SRCS:=$(wildcard $(SRC_PATH)/*.c)
OBJS:=$(addprefix $(OBJ_PATH)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(MLX_LIB) $(OBJS)
	$(CC) -L. -lmlx -framework OpenGL -framework AppKit -o $@ $(OBJS) 

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(FLAGS) -I$(MLX_PATH) -I$(INC_PATH) -c -o $@ $<

$(MLX_LIB):
	make -C $(MLX_PATH)
	cp $(MLX_PATH)/$@ ./$@

$(OBJ_PATH):
	@mkdir -p $@

clean:
	make clean -sC $(MLX_PATH)
	rm -rf $(OBJ_PATH) $(DEP_PATH)
	rm -f $(MLX_LIB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re 
