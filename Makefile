# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asougako <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 14:26:49 by asougako          #+#    #+#              #
#    Updated: 2017/12/12 20:56:20 by asougako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re, proper
.SUFFIXES:

NAME = libftprintf.a
CC = gcc
CF = -Wall -Wextra -Werror
AR = ar rcs
DEBUG = 0

ifeq ($(DEBUG), 1)
	DF = -g
else
	DF =
endif

RM = /bin/rm -f
HEAD_DIR = ./

INC_DIR = ./includes/
SRC_DIR = ./srcs/
TMP_DIR = ./tmp/

SRC_LIBFT =\
	ft_atoi.c			ft_bzero.c			ft_intlen.c		ft_isalnum.c\
	ft_isalpha.c		ft_isascii.c		ft_isdigit.c	ft_islower.c\
	ft_isprint.c		ft_isspace.c		ft_isupper.c	ft_itoa.c\
	ft_uitoa.c			ft_itoabase.c		ft_memalloc.c	ft_memccpy.c\
	ft_memchr.c			ft_memcmp.c			ft_memcpy.c		ft_memdel.c\
	ft_memmove.c		ft_memset.c			ft_memdup.c		ft_putchar.c\
	ft_putchar_fd.c		ft_putendl.c		ft_putendl_fd.c	ft_putnbr.c\
	ft_putnbr_fd.c		ft_putstr.c			ft_putnstr.c	ft_putstr_fd.c\
	ft_strcat.c			ft_strchr.c			ft_strclr.c		ft_strcmp.c\
	ft_strcpy.c			ft_strdel.c			ft_strdup.c		ft_strequ.c\
	ft_striter.c		ft_striteri.c		ft_strjoin.c	ft_strlcat.c\
	ft_strlen.c			ft_strmap.c			ft_strmapi.c	ft_strncat.c\
	ft_strncmp.c		ft_strncpy.c		ft_strnequ.c	ft_strnew.c\
	ft_strnstr.c		ft_strrchr.c		ft_strsplit.c	ft_strstr.c\
	ft_strsub.c			ft_strtab_add.c		ft_strtab_dup.c	ft_strtab_len.c\
	ft_strtab_new.c		ft_strtrim.c		ft_tolower.c	ft_toupper.c\
	ft_lstadd.c			ft_lstdel.c			ft_lstdelone.c	ft_lstiter.c\
	ft_lstmap.c			ft_lstnew.c			ft_strndup.c	ft_lstadd_tail.c\
	ft_lstdelif.c		ft_lstchr.c			ft_dict_new.c	ft_dict_add.c\
	ft_dict_del.c		ft_dict_find.c		ft_dict_print.c	get_next_line.c\
	ft_print_memory.c	ft_lowstr.c			ft_uppstr.c		ft_qsort.c\
	ft_putnstr_fd.c		ft_twos_complement.c				ft_uitoa.c\
	ft_uintlen.c

SRC_GETOPT =\
	ft_getopt.c			ft_getopt_parse.c				ft_getopt_print.c

SRC_FTPRINTF =\
	ft_printf.c			process.c       get_directives.c\
	arg_c.c				arg_s.c         arg_d.c         arg_u.c\
	arg_o.c				arg_x.c         arg_xupp.c      arg_p.c\
	process_specs.c		process_specs_s.c\
	process_specs_d.c	process_specs_u.c	arg_err.c	arg_mod.c

SRCS = $(SRC_LIBFT)\
	   $(addprefix ft_getopt/, $(SRC_GETOPT))\
	   $(addprefix ft_printf/, $(SRC_FTPRINTF))

OBJ =	$(addprefix objs/, $(SRCS:.c=.o))\

ECHO = echo
OS = $(shell uname -s)
ifeq ($(OS), Linux)
ECHO = echo -e
endif

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $@ $^
ifeq ($(DEBUG), 1)
	@$(ECHO) "Created library \033[32m$@\033[0m with debug flag."
else
	@$(ECHO) "Created library \033[32m$@\033[0m."
endif

objs/%.o: srcs/%.c
	@$(CC) -c $(DF) $(CF) $< -I $(INC_DIR) -o $@
	@$(ECHO) "Created object \033[32m$@\033[0m."

objs/ft_getopt/%.o: srcs/ft_getopt/%.c
	@$(CC) -c $(DF) $(CF) $< -I $(INC_DIR) -o $@
	@$(ECHO) "Created object \033[32m$@\033[0m."

clean:
	@$(RM) $(OBJ)
	@$(ECHO) "Removing \033[31mobjects\033[0m."

fclean: clean
	@$(RM) $(NAME)
	@$(ECHO) "Removing \033[31m$(NAME)\033[0m."

re: fclean all

proper: fclean all
	@$(RM) $(OBJ)
	@$(ECHO) "Removing \033[31mobjects\033[0m."
