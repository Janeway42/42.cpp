NAME = account

SRC = Account.cpp tests.cpp

OBJ = $(SRC:%.cpp=%.o)

CPP = clang++
FLAG = -Wall -Wextra -Werror -pedantic -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(FLAG) -o $@ $^

%.o: %.cpp
	$(CPP) $(FLAG) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re