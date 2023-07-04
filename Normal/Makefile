NAME = so_long.out

SRC = $(MAIN_SRC) $(SRC_GNL) $(SRC_MAP) $(SRC_GAME) $(SRC_PRINTF)

MAIN_SRC = ./*.c

LIBFT_A = libft.a
LIBF_DIR = ../libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

PRINTF_DIR = ../My_Printf/
PRINTF_A = libftprintf.a
PRINTF  = $(addprefix $(PRINTF_DIR), $(PRINTF_A))

GNL = get_next_line.c get_next_line_utils.c
SRC_GNL = $(addprefix ../GNL/, $(GNL))

MAP = parsing.c map_validity.c sprites.c map_path.c
SRC_MAP = $(addprefix ./map_parsing/, $(MAP))

GAME =	movement.c
SRC_GAME = $(addprefix ./, $(GAME))

OBJ = *.o

FLAGS = -Wall -Wextra -Werror
INCLUDE = -lmlx -framework OpenGL -framework AppKit

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making libft and printf..." $(NONE)
	@make -C $(PRINTF_DIR)
	@make -C $(LIBF_DIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@gcc $(FLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(INCLUDE) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC)

exe: re
	@make -C ./ clean
	@echo $(YELLOW)"     - Executing $(NAME)... \n"$(NONE)
	@./$(NAME) $(m)
	@echo $(YELLOW)"\n     - Done -"$(NONE)
clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ)
	@make -C $(LIBF_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME)
	@make -C $(LIBF_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all
