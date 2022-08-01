NAME = yellow_pages

SRC =	YellowPages.cpp\
		functions_PhoneBook.cpp\
		functions_Contact.cpp\

OBJ = $(SRC:%.cpp=%.o)

FLAGS = -Wall -Werror -Wextra

CPP = clang++

all: $(NAME)

$(NAME): $(OBJ)
	@$(CPP) $(FLAGS) -o $@ $^
	@echo "\033[0;31myellow_pages ready\033[0m"

%o: %.cpp
	@$(CPP) $(FLAG) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@echo "clean done"

fclean:
	@rm -f $(NAME)
	@echo "fclean done"

re: fclean all

.PHONY: all clean fclean re