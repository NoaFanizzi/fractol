# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nofanizz <nofanizz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 13:45:35 by nofanizz          #+#    #+#              #
#    Updated: 2025/03/18 14:53:39 by nofanizz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


BINARIES	= fractol fractol_bonus

ifeq ($(filter bonus clean fclean,$(MAKECMDGOALS)),)
	include mandatory/mandatory.mk
endif

ifeq ($(MAKECMDGOALS), bonus)
	include bonus/bonus.mk
endif

OBJ_DIR = .obj
DEP_DIR = .dep
LIBFT_DIR = libft
MINILIBX_DIR = minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx.a

LIBFT		= $(LIBFT_DIR)/libft.a

CC		= cc
C_FLAGS = -Wall -Wextra -Werror
D_FLAGS = -MMD -MP -MF $(DEP_DIR)/$*.d
I_FLAGS = -I$(INC_DIR) -I$(LIBFT_DIR)/includes -I$(MINILIBX_DIR)
L_FLAGS = -L$(LIBFT_DIR) -lft
CF		= $(CC) $(C_FLAGS) $(I_FLAGS)

#MLX
MLX_FLAGS = -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

vpath %.c $(LIBFT_DIR)/srcs
vpath %.h $(LIBFT_DIR)/includes
vpath %.o $(OBJ_DIR) $(LIBFT_DIR)/$(OBJ_DIR)
vpath %.d $(DEP_DIR) $(LIBFT_DIR) /$(DEP_DIR)

OBJS	= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
DEPS	= $(addprefix $(DEP_DIR)/, $(notdir $(SRCS:.c=.d)))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@echo "Creating $(NAME)\n"
	@$(CF) $^ $(L_FLAGS) $(MLX_FLAGS) -o $@
	@echo "Program Created \n"

bonus: $(NAME)

$(MINILIBX):
	@$(MAKE) -s -C $(MINILIBX_DIR)
	
$(LIBFT): FORCE
	@echo "Bulding libft \n"
	@$(MAKE) -s -C $(LIBFT_DIR)
	
$(OBJ_DIR)/%.o: %.c  $(DEP_MK_DIR) Makefile| $(OBJ_DIR) $(DEP_DIR)
	@echo "Compilation $< $@ "
	@$(CF) $(D_FLAGS) -c $< -o $@

$(OBJ_DIR) $(DEP_DIR):
	@echo "Creating obj directory"
	@mkdir -p $@

clean:
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MINILIBX_DIR) clean
	@echo "Deleting obj files"
	@rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@echo "Deleting obj files"
	@echo "Removing binaries"
	@rm -f $(BINARIES)

re: fclean all
	@echo "Recompilation terminée ✅"
	
-include $(DEPS)

.PHONY: all clean fclean re debug help
FORCE:
