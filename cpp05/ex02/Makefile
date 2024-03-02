# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetros <tpetros@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 09:54:53 by tpetros           #+#    #+#              #
#    Updated: 2024/01/03 23:00:52 by tpetros          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alotforms

SRC = Bureaucrat.cpp main.cpp AForm.cpp ShrubberyCreationForm.cpp \
	  RobotomyRequestForm.cpp PresidentialPardonForm.cpp

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

OBJS = $(SRC:.cpp=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) *.txt

re: fclean all

.PHONY: clean fclean all re