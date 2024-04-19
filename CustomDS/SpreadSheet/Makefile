NAME		= spreadsheet

SRC			= main.cpp Cell.cpp SpreadSheet.cpp Column.cpp
OBJ			= $(SRC:.cpp=.o)
CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g3

RM			= rm -rf

PRINTF		= printf

PURPLE		:= \033[0;34m
PINK		:= \033[0;35m
RESET		:= \033[0m

all:		$(NAME)

$(NAME):	$(OBJ) Makefile
			$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
			@$(PRINTF) "\r%100s\r$(PINK)☽ $(PURPLE)SpreadSheet $(PINK)successfully compiled! $(RESET)\n"

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			@$(PRINTF) "\r%100s\r$(PINK)☽ $(PURPLE)SpreadSheet $(PINK)successfully cleaned! $(RESET)\n"


re:			fclean $(NAME)

.PHONY:		all clean fclean re