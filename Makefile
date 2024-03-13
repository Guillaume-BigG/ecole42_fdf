# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 14:30:03 by gbeaudoi          #+#    #+#              #
#    Updated: 2024/02/23 20:33:36 by gbeaudoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################### COLORS #####################################

RESET		:=	\e[0m
BOLD		:=	\e[1m
DIM		:=	\e[2m
ITAL		:=	\e[3m
UNDERLINE	:=	\e[4m

BLACK		:=	\e[30m
GRAY		:=	\e[90m
RED		:=	\e[31m
GREEN		:=	\e[32m
YELLOW		:=	\e[33m
ORANGE		:=	\e[38;5;208m
BLUE		:=	\e[34m
PURPLE		:=	\e[35m
PINK		:=	\033[38;2;255;182;193m
CYAN		:=	\e[36m

BRIGHT_BLACK	:=	\e[90m
BRIGHT_GREEN	:=	\e[92m
BRIGHT_YELLOW	:=	\e[93m
BRIGHT_BLUE	:=	\e[94m
BRIGHT_PURPLE	:=	\e[95m
BRIGHT_CYAN	:=	\e[96m


################################### BASICS ###################################

NAME		=	fdf
# NAME_BONUS  =	fdf_bonus

LIBFT = libft/
MINILIBX = minilibx-linux/

CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror -I
INC		=	include/
LIBC		=	ar -rcs
RM		=	rm -rf

MLXFLAGS	=	-lXext -lX11 -lm

################################### SOURCES ###################################

SRC	= 				bresenham.c color_calculation.c color_palette.c draw_display.c draw_menu.c draw_utils.c initialization.c keyboard_event.c \
					main.c map_reading.c math_projection.c math_utils.c memory_allocation.c mouse_event.c parsing_check.c utils.c free.c initialization_part2.c
					
SRC_BONUS	= 					bresenham.c color_calculation.c color_palette.c draw_display.c draw_menu.c draw_utils.c initialization.c keyboard_event.c \
					main.c map_reading.c math_projection.c math_utils.c memory_allocation.c mouse_event.c parsing_check.c utils.c free.c initialization_part2.c

######################## COMBINE DIRECTORIES AND FILES ########################

SRC_DIR		= src/
# SRC_DIR_BONUS = src/

SRC_NAMES	= $(SRC)
# SRC_NAMES_BONUS = $(SRC_BONUS)

OBJ_DIR		= obj/
# OBJ_DIR_BONUS = obj/

OBJ	= $(SRC_NAMES:.c=.o)
# OBJ_BONUS	= $(SRC_NAMES_BONUS:.c=.o)

OBJ_FOLDERS	= $(addprefix $(OBJ_DIR), $(OBJ))
# OBJ_BONUS_FOLDERS = $(addprefix $(OBJ_DIR_BONUS), $(OBJ_BONUS))

#################################### MANDATORY ####################################

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			@mkdir -p $(dir $@)
			@printf "$(ITAL)$(GREEN)Compiling: $(RESET)$(ITAL)$<\n"
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# link .o files to the library
$(NAME):	$(OBJ_FOLDERS)	
			@make -C $(LIBFT)
			@make -C $(MINILIBX)
			@cp $(MINILIBX)/libmlx.a .
			@cp $(LIBFT)/libft.a .
			@printf "\n $(BOLD)$(YELLOW)MiniLibX and Libft ready! $(RESET)\n"
			@printf "$(RESET)$(BOLD)$(CYAN)[fdf]:\t$(RESET)"
			@$(CC) $(CFLAGS) $(INC) $(MLXFLAGS) $(OBJ_FOLDERS) -L$(MINILIBX) -lmlx -L$(LIBFT) -lft -o $(NAME)
			@printf "$(PINK) ./fdf ready to map out $(RESET)\n"


all:		$(NAME)

#################################### BONUS ####################################

# $(OBJ_DIR_BONUS)%.o: $(SRC_DIR_BONUS)%.c
# 			@mkdir -p $(dir $@)
# 			@printf "$(ITAL)$(GREEN)Compiling bonus: $(RESET)$(ITAL)$<\n"
# 			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# # link .o files to the library
# $(NAME_BONUS):	$(OBJ_BONUS_FOLDERS)	
# 			@make -C $(MAKEFLAGS) $(LIBFT)
# 			@make -C $(MAKEFLAGS) $(NINILIBX)
# 			@cp $(MINILIBX)/libmlx .
# 			@cp $(LIBFT)/libft.a .
# 			@make all
# 			@printf "\n $(BOLD)$(YELLOW)MiniLibX and Libft ready! $(RESET)\n"
# 			@printf "$(RESET)$(BOLD)$(CYAN)[fdf_bonus]:\t$(RESET)"
# 			@$(CC) $(CFLAGS) $(INC) $(MLXFLAGS) $(OBJ_BONUS_FOLDERS) libmlx libft.a -o $(NAME_BONUS)
# 			@printf "$(PINK) ./fdf with bonus ready to map out $(RESET)\n"

# all:		$(NAME_BONUS)

#################################### RULES ####################################

clean:
		@$(RM) $(OBJ_DIR)
		@make clean -C $(MINILIBX) $(MAKEFLAGS)
		@make clean -C $(LIBFT) $(MAKEFLAGS)
		@printf "$(BOLD)$(PINK)[fdf]: $(RESET)$(PINK)object files $(RESET)\t\t=> CLEANED! \n\n"

fclean: 	clean
			@$(RM) $(NAME) $(BONUS)
			@$(RM) $(MINILIBX)/libmlx.a $(LIBFT)/libft.a
			@$(RM) libmlx.a libft.a
			@printf "$(BOLD)$(BLUE)[MiniLibX]: $(RESET)$(BLUE)exec. files $(RESET)\t=> CLEANED! \n\n"
			@printf "$(BOLD)$(PURPLE)[LIBFT]: $(RESET)$(PURPLE)exec. files $(RESET)\t=> CLEANED! \n\n"
			@printf "$(BOLD)$(BRIGHT_PURPLE)[fdf]: $(RESET)$(BRIGHT_PURPLE)exec. files $(RESET)\t=> CLEANED! \n\n"

re:		fclean all
			@printf "\n\n $(BOLD)$(YELLOW)Cleaning done! $(RESET)\n"
			
.PHONY:		all clean fclean re bonus