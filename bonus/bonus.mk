NAME		= fractol_bonus

DIR			= bonus
SRC_DIR		= $(DIR)/srcs
INC_DIR		= $(DIR)/includes
FRC_DIR		= fractals
UTILS_DIR	= utils
DEP_MK_DIR  = $(DIR)/bonus.mk

FRC_SRCS	= julia_bonus.c mandelbrot_bonus.c
FRC_SRCS	:= $(addprefix $(FRC_DIR)/, $(FRC_SRCS))

UTILS_SRCS	= atod_bonus.c hook_bonus.c parsing_bonus.c screen_settings_bonus.c utils_bonus.c zoom_bonus.c colors_bonus.c
UTILS_SRCS	:= $(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))

SRCS		= main_bonus.c fractol_bonus.c historic_bonus.c\
			  $(FRC_SRCS) $(UTILS_SRCS)
SRCS		:= $(addprefix $(SRC_DIR)/, $(SRCS))


vpath %.c $(SRC_DIR) $(SRC_DIR)/$(FRC_DIR) $(SRC_DIR)/$(UTILS_DIR)
vpath %.h $(INC_DIR)