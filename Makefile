##################################BEG###
NAME = minishell

#---------------------------------------#
#               VARIABLES               #
#---------------------------------------#

SOURCES = $(SRC)main.c \
$(SRC)receiving_command.c \
$(SRC)exec_command.c \
$(SRC)child.c \
$(SRC)ft_close.c \
$(SRC)add_path_to_cmd.c \
$(SRC)find_acces.c \
$(SRC)parsing_file.c

#---------------------------------------#
#               COMMANDS                #
#---------------------------------------#

CC = cc

RFLAGS = -Wall -Werror -Wextra -I libft
DFLAGS = -MMD -MP
FLAGS = $(RFLAGS) $(DFLAGS)

#-I include permet de pas mettre le chemin pr les include
#MMD: crrer ficher dep  MP:gere si le fichier a ete modifier ou sup
#ARFLAGS = ar -rc
#r: replace old obj  s: ecrire ds index ou le mettre a j
#c: creer la bibli si exist pa  ar:maj de la bibli

RM = rm -fr

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

SRC = src/

INCLUDE = header

OBJ_DIR = .build

#---------------------------------------#
#               RULES                   #
#---------------------------------------#

OBJ = $(SOURCES:%.c=${OBJ_DIR}/%.o)

DEPS_FILES = ${OBJ:%.o=%.d}

all: $(NAME)

-include $(DEPS_FILES)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) -L$(LIBFTDIR) -lreadline -lft -o $(NAME)
	 
$(LIBFT): FORCE
	@make -C $(LIBFTDIR)

$(OBJ_DIR)/$(SRC)%.o: $(SRC)%.c
	@mkdir -p $(OBJ_DIR)/src
	$(CC) $(FLAGS) -I $(INCLUDE) -o $@ -c $<

clean:
	make -C $(LIBFTDIR) clean
	${RM} $(OBJ) $(DEPS_FILES) $(OBJ_DIR)
	
fclean: clean
	make -C $(LIBFTDIR) fclean
	${RM} $(NAME)
	
re: fclean all

FORCE:

.PHONY: clean fclean all re force

#.PHONY : print%
#print% :
#   @echo $(patsubst print%,%,$@)=
#   @echo $($(patsubst print%,%,$@))

###############################_END_###
