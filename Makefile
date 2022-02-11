NAME = 4_in_a_row

INC = includes

FLAGS = -Wall -Wextra -Werror -std=c++98 -I $(INC)

CXX = @clang++ $(FLAGS)

SRCS =	srcs/main.cpp\
		srcs/board.cpp


OBJ = $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJ)
			$(CXX) $(OBJ) -o $(NAME)
			@echo "\033[32mCOMPILATION OK\033[0m"
			
clean:
		@rm -rf $(OBJ)
		@echo "\033[36mCLEAN OK\033[0m"

fclean: clean
		@rm -rf $(NAME)
		@echo "\033[36mFCLEAN OK\033[0m"

re: fclean all

.PHONY: all fclean clean re
