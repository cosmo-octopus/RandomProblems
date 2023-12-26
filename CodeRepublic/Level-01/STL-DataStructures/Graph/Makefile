NAME		= graph

SRC			= main.cpp Graph.cpp
OBJ			= $(SRC:.cpp=.o)
CC			= g++
CPPFLAGS	= -Wall -Wextra -Werror -pedantic -g -O1 -fsanitize=address #-std=c++98

RM			= rm -rf

PRINTF		= printf

PURPLE		:= \033[0;34m
PINK		:= \033[0;35m
RESET		:= \033[0m

all:		$(NAME)

$(NAME):	$(OBJ) Makefile
			@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
			@$(PRINTF) "\r%100s\r$(PINK)☽ $(PURPLE)My Graph $(PINK)successfully compiled! $(RESET)\n"

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			@$(PRINTF) "\r%100s\r$(PINK)☽ $(PURPLE)My Graph $(PINK)successfully cleaned! $(RESET)\n"

re:			fclean $(NAME)

.PHONY:		all clean fclean re