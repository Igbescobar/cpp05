# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igngonza <igngonza@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 12:12:35 by igngonza          #+#    #+#              #
#    Updated: 2026/01/14 12:24:31 by igngonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Bureaucrat
CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

OBJ_DIR		= objs

SOURCES		= main.cpp \
			  Bureaucrat.cpp

OBJS		= $(addprefix $(OBJ_DIR)/,$(SOURCES:.cpp=.o))
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bear

