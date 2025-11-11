# ============================================================================ #
#                                  VARIABLES                                   #
# ============================================================================ #
# Nom de la bibliothèque
NAME		= libft.a
# Compilateur et flags
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f
# Couleurs pour affichage
GREEN		= \033[0;32m
RED		= \033[0;31m
BLUE		= \033[0;34m
YELLOW		= \033[0;33m
RESET		= \033[0m
# ============================================================================ #
#                              FICHIERS SOURCES                                #
# ============================================================================ #
# Fonctions de test de caractères
SRCS_IS		= ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \

# Fonctions de conversion
SRCS_TO		= ft_toupper.c \
			  ft_tolower.c \
			  ft_atoi.c \

# Fonctions de memory
SRCS_MEM = ft_memset.c \
	   	ft_memcpy.c \
	   	ft_memmove.c \
	   	ft_bzero.c \
	   	ft_calloc.c \
	   	ft_memchr.c \
	   	ft_memcmp.c \

# Fonctions de manipulation string
SRCS_STR = ft_strchr.c \
	  	ft_strdup.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c

# Fonctions part 2
SRCS_AD = ft_strmapi.c \
	  	ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_itoa.c \
		ft_split.c \

SRCS		= $(SRCS_IS) $(SRCS_TO) $(SRCS_MEM) $(SRCS_STR) $(SRCS_AD)

# Fichiers objets
OBJS		= $(SRCS:.c=.o)

# ============================================================================ #
#                                   RÈGLES                                     #
# ============================================================================ #


all: $(NAME)
# Création de la bibliothèque
$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)✓ $(NAME) créée avec succès !$(RESET)"

# Compilation des fichiers .c en .o
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(BLUE)Compilation de $<...$(RESET)"

# Nettoyage des fichiers objets
clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)✓ Fichiers objets supprimés$(RESET)"

# Nettoyage complet (objets + bibliothèque)
fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)✓ $(NAME) supprimée$(RESET)"

# Recompilation complète
re: fclean all
# Indique que ces règles ne correspondent pas à des fichiers
.PHONY: all clean fclean re
