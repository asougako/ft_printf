# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asougako <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 14:26:49 by asougako          #+#    #+#              #
#    Updated: 2017/06/01 19:08:46 by asougako         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re, proper
.SUFFIXES:

NAME = ft_printf.a
CC = gcc
CF = -Wall -Wextra -Werror
AR = ar
INC = -I ../lib/
DEBUG = 0
ifeq ($(DEBUG), 1)
	DF = -g
else
	DF =
endif
RM = /bin/rm -f
HEAD_DIR = ./
SRC_DIR = ./src/
#		|				|				|				|				|
SRC =	ft_printf.c		process.c \
		arg_c.c			arg_s.c			arg_d.c

OBJ = $(SRC:.c=.o)
ECHO = echo
OS = $(shell uname -s)
ifeq ($(OS), Linux)
ECHO = echo -e
endif

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) rc $(NAME) $^
ifeq ($(DEBUG), 1)
	@$(ECHO) "Created library \033[32m$@\033[0m with debug flag."
else
	@$(ECHO) "Created library \033[32m$@\033[0m."
endif

%.o: $(SRC_DIR)%.c
	@$(CC) $(INC) $(DF) $(CF) -c $^ -I $(HEAD_DIR)
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
