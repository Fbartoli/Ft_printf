# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 15:47:25 by flbartol          #+#    #+#              #
#    Updated: 2019/02/08 12:06:02 by apsaint-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME= libftprintf.a
EXEC = printf
FLAGS= -Wall -Wextra -Werror

NOC=\033[0m	  #Reset text
OKC=\033[32m  #Green
ERC=\033[31m  #Red
WAC=\033[33m  #Yellow

LIB= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
		ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
		ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_is_space.c ft_memalloc.c ft_memdel.c \
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
		ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
		ft_lstiter.c ft_lstmap.c ft_index_rev.c ft_index.c\
		ft_max.c ft_max_int.c ft_min_int.c ft_min.c ft_nbrlen.c\
		ft_itoa_base.c ft_nbchar.c ft_pow.c ft_itoa_base_hex.c ft_hash.c\
		ft_putnstr.c ft_itoa_u.c ft_putnbrpf.c ft_putflt.c ft_putunbrpf.c\
		ft_putunbr.c ft_unbrlen.c ft_itoa_binaire.c

SRC = conversions_csp.c ft_printf.c print_int.c print_u.c\
		parser.c print_args.c utils.c  utilsbis.c conversions_d.c\
		print_o.c print_hex.c print_f.c print_u.c util_o.c conversions_uni.c\
		conversions_b.c


MAIN = main.c

HEADER= includes
LIB_DIR = libft/
OBJ_DIR = objects/
SRC_DIR = srcs/

OBJ_LIB:= $(addprefix $(OBJ_DIR),$(LIB:.c=.o))
OBJ_SRC:= $(addprefix $(OBJ_DIR),$(SRC:.c=.o))
LIB := $(addprefix $(LIB_DIR),$(LIB))
SRC := $(addprefix $(SRC_DIR),$(SRC))

all: $(EXEC)

$(OBJ_DIR):
	@mkdir $@

$(EXEC): $(NAME) $(MAIN)
	@echo "======"
	@gcc -o $(EXEC) $(NAME) $(MAIN)
	@echo "$(OKC)$(EXEC):\t\t$(EXEC) ready$(NOC)"

$(NAME): $(OBJ_DIR) $(OBJ_SRC) $(OBJ_LIB)
	@echo "======"
	@ar rcs $(NAME) $(OBJ_SRC) $(OBJ_LIB)
	@echo "$(OKC)$(NAME):\t\t$(NAME) ready$(NOC)"

$(OBJ_DIR)%.o: $(LIB_DIR)%.c
	@cc $(FLAGS) -o $@ -c $< -I $(HEADER)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@cc $(FLAGS) -o $@ -c $< -I $(HEADER)

clean:
	@echo "======"
	@rm -rf $(OBJ_DIR)
	@echo "$(ERC)$(NAME):\t\tRemoving OBJ path: ./obj/$(NOC)"

fclean: clean
	@echo "======"
	@rm -rf $(NAME)
	@rm -rf $(EXEC)
	@echo "$(WAC)$(NAME):\t\tRemoving $(NAME)$(NOC)"

re: fclean all

.PHONY: clean fclean re all
