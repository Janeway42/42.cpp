NAME = harl

SRC =	main.cpp\
		Harl.cpp

OBJ = $(SRC:%.cpp=%.o)

FLAGS = -Wall -Werror -Wextra -std=c++98

CPP = c++

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(FLAGS) -o $@ $^
	@echo "\033[0;31mreplace without replace ready\033[0m"

%o: %.cpp
	@$(CPP) $(FLAG) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@echo "clean done"

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo "fclean done"

re: fclean all

.PHONY: all clean fclean re