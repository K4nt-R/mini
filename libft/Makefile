###################################BEG###
NAME = libft.a

#---------------------------------------#
#				VARIABLES				#
#---------------------------------------#



SOURCES = ft_isalpha.c \
	     ft_isdigit.c \
	     ft_isalnum.c \
	     ft_isascii.c \
	     ft_isprint.c \
	     ft_strlen.c \
	     ft_memset.c \
	     ft_bzero.c \
	     ft_memcpy.c \
	     ft_memmove.c \
	     ft_strlcpy.c \
	     ft_strlcat.c \
	     ft_toupper.c \
	     ft_tolower.c \
	     ft_strchr.c \
	     ft_strrchr.c \
	     ft_strncmp.c \
	     ft_memchr.c \
	     ft_memcmp.c \
	     ft_strnstr.c \
	     ft_atoi.c \
	     ft_calloc.c \
	     ft_strdup.c \
	     ft_substr.c \
	     ft_strjoin.c \
	     ft_strtrim.c \
	     ft_split.c \
	     ft_itoa.c \
	     ft_strmapi.c \
	     ft_striteri.c \
	     ft_putchar_fd.c \
	     ft_putstr_fd.c \
	     ft_putendl_fd.c \
	     ft_putnbr_fd.c \

BONUS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \

#---------------------------------------#
#				COMMANDS				#
#---------------------------------------#

CC = cc

RFLAGS = -Wall -Werror -Wextra
DFLAGS = -MMD -MP -I include
#-I include permet de pas mettre le chemin pr les include
#MMD: crrer ficher dep  MP:gere si le fichier a ete modifier ou sup
ARFLAGS = ar -rc 
#r: replace old obj  s: ecrire ds index ou le mettre a j
#c: creer la bibli si exist pa  ar:maj de la bibli

RM = rm -fr

OBJ_DIR = .build

#---------------------------------------#
#				RULES					#
#---------------------------------------#

all: $(NAME)

OBJ = $(SOURCES:%.c=${OBJ_DIR}/%.o)

OBJECT2 = $(BONUS:%.c=${OBJ_DIR}/%.o)

DEPS_FILES = ${OBJ:.o=.d} ${OBJECT2:.o=.d}
#DEPS_FILES = $(${OBJ:.o}${OBJECT2:.o}=${OBJ_DIR}/%.d)

-include $(DEPS_FILES)

$(NAME): $(OBJ_DIR) $(OBJ)
	 ${ARFLAGS} $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(FLAGS) ${DFLAGS} -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	${RM} $(OBJ) $(OBJECT2) $(DEPS_FILES) $(OBJ_DIR)

fclean: clean
	${RM} $(NAME)

re: fclean all 

bonus: $(OBJ) $(OBJECT2)
	$(MAKE) $(NAME) SOURCES="$(SOURCES) $(BONUS)"

.PHONY: clean fclean all re bonus
###############################_END_###
