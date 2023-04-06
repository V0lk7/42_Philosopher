# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduval <jduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 11:36:44 by jduval            #+#    #+#              #
#    Updated: 2023/04/06 18:14:18 by jduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	philo

MAKEFLAGS	+=	--no-print-directory

###############################################################################

SRC_DIR 	=	mandatory

OBJ_DIR 	=	.obj

SRCS		:=	main_philo.c				\
				parsing/parse_user_input.c	\
				parsing/create_database.c	\
				parsing/parsing_utils.c		\

SRCS		:=	$(SRCS:%=$(SRC_DIR)/%)

OBJS 		:=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

DEPS		:=	$(OBJS:.o=.d)

###############################################################################

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -pthread -ggdb3

CPPFLAGS	=	-MMD -MP

DIRDUP 		= 	mkdir -p $(@D)

###############################################################################

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) $(OBJS) -o $(NAME)
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o : %.c
	@$(DIRDUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	@rm -rf $(OBJ_DIR)
.PHONY: clean

fclean: clean
	@rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
