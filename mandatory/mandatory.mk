NAME		= fractol

DIR			= mandatory
SRC_DIR		= $(DIR)/srcs
INC_DIR		= $(DIR)/includes
FRC_DIR		= fractals
UTILS_DIR	= utils
DEP_MK_DIR  = $(DIR)/mandatory.mk

FRC_SRCS	= julia.c mandelbrot.c
FRC_SRCS	:= $(addprefix $(FRC_DIR)/, $(FRC_SRCS))

UTILS_SRCS	= atod.c hook.c parsing.c screen_settings.c utils.c zoom.c colors.c
UTILS_SRCS	:= $(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))

SRCS		= main.c fractol.c \
			  $(FRC_SRCS) $(UTILS_SRCS)
SRCS		:= $(addprefix $(SRC_DIR)/, $(SRCS))


vpath %.c $(SRC_DIR) $(SRC_DIR)/$(FRC_DIR) $(SRC_DIR)/$(UTILS_DIR)
vpath %.h $(INC_DIR)