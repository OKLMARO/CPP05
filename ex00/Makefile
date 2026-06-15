# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oamairi <oamairi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/15 16:55:48 by oamairi           #+#    #+#              #
#    Updated: 2026/06/15 16:56:31 by oamairi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ex00

CC		=	c++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS	=	Bureaucrat.cpp main.cpp

OBJS	=	$(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
