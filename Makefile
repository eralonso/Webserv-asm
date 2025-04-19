NAME := Webserv

NULL =
SPACE = $(NULL) #

BIN_ROOT = bin/
INC_ROOT = inc/
SRC_ROOT = src/
OBJ_ROOT = .obj/

NAME := $(BIN_ROOT)$(NAME)

SRCS = main.asm

OBJS = $(SRCS:%.asm=$(OBJ_ROOT)%.o)

HEADERS := . syscall

SRCS_DIRS := ./
SRCS_DIRS := $(subst :,$(SPACE),$(SRCS_DIRS))
SRCS_DIRS := $(addprefix $(SRC_ROOT),$(SRCS_DIRS))
SRCS_DIRS := $(subst $(SPACE),:,$(SRCS_DIRS))

INCLUDE := $(addprefix -I$(INC_ROOT),$(HEADERS))

AS := nasm
ASFLAGS := -f elf64 -g

RM = rm -rf
MKDIR = mkdir -p

CREATE_DIRS := $(BIN_ROOT) $(OBJ_ROOT)

vpath %.asm $(SRCS_DIRS)

.PHONY: all clean fclean re

all: $(NAME)

$(CREATE_DIRS):
	$(MKDIR) $@

$(OBJS): $(OBJ_ROOT)%.o: %.asm
	$(AS) $(ASFLAGS) $(INCLUDE) $< -o $@

$(NAME):: $(CREATE_DIRS)

$(NAME):: $(OBJS)
	$(LD) -o $@ $(OBJS)

clean:
	$(RM) $(OBJ_ROOT)

fclean: clean
	$(RM) $(BIN_ROOT)

re: fclean all

.SILENT: $(OBJS) $(CREATE_DIRS)
