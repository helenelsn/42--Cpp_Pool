# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Helene <Helene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 15:15:04 by Helene            #+#    #+#              #
#    Updated: 2023/10/09 17:00:40 by Helene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = c++
CFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD # -g3
RM = rm -f

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $<

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

.PHONY : 
	all clean fclean re