# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asougako <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 14:26:49 by asougako          #+#    #+#              #
#    Updated: 2017/12/11 19:45:31 by asougako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re, proper
.SUFFIXES:

NAME = ft_printf.a
CC = gcc
AR = ar
INC = -I ./ -I ./lib/

DEBUG = 0
ifeq ($(DEBUG), 1)
	CF =
	DF = -g
else
	CF = -Wall -Wextra -Werror
	DF =
endif

RM = /bin/rm -f
SRC_DIR = ./src/
#		|				|				|				|				|
SRC =	ft_printf.c		process.c		get_directives.c\
		arg_c.c			arg_s.c			arg_d.c			arg_u.c\
		arg_o.c			arg_x.c			arg_xupp.c		arg_p.c\
		process_specs.c

OBJ = $(SRC:.c=.o)
OS = $(shell uname -s)
ifeq ($(OS), Linux)
ECHO = echo -e
else
ECHO = echo
endif

all: $(NAME)
	cd lib && make

$(NAME): $(OBJ)
	cd lib && make
	@$(AR) rc $(NAME) $^
ifeq ($(DEBUG), 1)
	@$(ECHO) "Created library \033[32m$@\033[0m with debug flag."
else
	@$(ECHO) "Created library \033[32m$@\033[0m."
endif

%.o: $(SRC_DIR)%.c
	@$(CC) $(DF) $(CF) -c $^ $(INC)
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
