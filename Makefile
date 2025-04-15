# **************************************************************************** #
#                                SO_LONG MAKEFILE                              #
# **************************************************************************** #

# Compiler and flags
CC      = cc
# CFLAGS  = -Wall -Wextra -Werror 
CFLAGS  = -Wall -Wextra -Werror -fsanitize=address -g3 -O0

# Directories
SRC_DIR     = src
INC_DIR     = include
LIB_DIR     = lib
LIBFT_DIR   = $(LIB_DIR)/libft
MLX_DIR     = $(LIB_DIR)/minilibx-linux

# Libraries
LIBFT_A     = $(LIBFT_DIR)/libft.a
MLX_LIB     = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
LIBFT_LIB   = -L$(LIBFT_DIR) -lft

# Source files
SRCS    = $(wildcard $(SRC_DIR)/*.c)
OBJS    = $(SRCS:.c=.o)

# Executable
NAME    = so_long

# Default target
all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@echo "Compiling libft..."
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) -I$(INC_DIR) -I$(LIBFT_DIR) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME)

# Clean up object files
clean:
	@echo "Cleaning object files..."
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Clean up everything
fclean: clean
	@echo "Cleaning executable and libft.a..."
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Recompile from scratch
re: fclean all

# Run the game with a test map
run: all
	./$(NAME) maps/test.ber

.PHONY: all clean fclean re run
