#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msymkany <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 12:52:11 by msymkany          #+#    #+#              #
#    Updated: 2017/11/04 14:15:55 by msymkany         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME := ft_retro

CXX := @clang++
FL := -Wall -Wextra -Werror

SOURCE := main.cpp \

OBJECTS := $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
		@$(CXX) $(FL) $(OBJECTS) -o $(NAME)
		@echo "The project is ready"

%.o: %.c
	$(CXX) $(FL) -c $< -o $@

.PHONY: clean fclean re

clean:
	@rm -f $(OBJECTS)
	@rm -f *~ *#
	@echo "It's clean"

fclean: clean
	@rm -f $(NAME)

re: fclean all