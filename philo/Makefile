# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jduval <jduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 11:36:44 by jduval            #+#    #+#              #
#    Updated: 2023/04/27 11:29:05 by jduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	philo

MAKEFLAGS	+=	--no-print-directory

###############################################################################

SRC_DIR 	=	mandatory

OBJ_DIR 	=	.obj

SRCS		:=	main_philo.c					\
				parsing/parse_user_input.c		\
				parsing/create_database.c		\
				parsing/parsing_utils.c			\
				parsing/create_data_struct.c	\
				utils/clear_data.c				\
				utils/error_philosophers.c		\
				utils/process_utils.c			\
				utils/print.c					\
				jobs/eat.c						\
				jobs/sleep.c					\
				jobs/think.c					\
				jobs/death.c					\

SRCS		:=	$(SRCS:%=$(SRC_DIR)/%)

OBJS 		:=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

DEPS		:=	$(OBJS:.o=.d)

###############################################################################

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror 

CPPFLAGS	=	-MMD -MP

DIRDUP 		= 	mkdir -p $(@D)

###############################################################################

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) $(OBJS) -lpthread -o $(NAME)
	$(info CREATED $(NAME))

$(OBJ_DIR)/%.o : %.c
	@$(DIRDUP)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

-include $(DEPS)

clean:
	rm -rf .obj
.PHONY: clean

fclean: clean
	rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
