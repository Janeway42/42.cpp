NAME = amateria

SRC =	main.cpp\
		AMateria.cpp\
		Ice.cpp\
		Cure.cpp\
		ICharacter.cpp\
		Character.cpp

OBJ = $(SRC:%.cpp=%.o)

FLAGS = -Wall -Werror -Wextra -std=c++98 -g

CPP = c++

all: $(NAME)

$(NAME): $(OBJ)
		$(CPP) $(FLAGS)  -o $@ $^
		@echo "\033[0;31mamateria ready\033[0m"

%.o: %.cpp
		$(CPP) -c $< -g -o $@

clean:
		@rm -f $(OBJ)
		@echo "clean done"

fclean:
		@rm -f $(OBJ)
		@rm -f $(NAME)
		@echo "fclean done"

re: fclean all

.PHONY: all clean fclean re
