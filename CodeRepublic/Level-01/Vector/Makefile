NAME		= vector

SRC			= main.cpp
OBJ			= $(SRC:.cpp=.o)
CC			= g++
CPPFLAGS	= -Wall -Wextra -Werror -pedantic #-std=c++98

RM			= rm -rf

PRINTF		= printf

PURPLE		:= \033[0;34m
PINK		:= \033[0;35m
RESET		:= \033[0m

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
			@$(PRINTF) "\r%100s\r$(PINK)☽ $(PURPLE)My Vector $(PINK)successfully compiled! $(RESET)\n"

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			@$(PRINTF) "\r%100s\r$(PINK)☽ $(PURPLE)ex02 $(PINK)successfully cleaned! $(RESET)\n"

re:			fclean $(NAME)

.PHONY:		all clean fclean re