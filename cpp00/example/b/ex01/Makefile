# **************************************************************************** #
#                                                                              #
#                                                        ..eeeee..             #
#    Makefile                                          e8'   8   '8e           #
#                                                     d8     8     8b          #
#    By: dries <sanderlegit@gmail.com>                8!   .dWb.   !8          #
#                                                     Y8 .e* 8 *e. 8P          #
#    Created: 2021/03/24 17:21:12 by dries             *8*   8   *8*           #
#    Updated: 2021/03/24 17:24:16 by dries               **ee8ee**             #
#                                                                              #
# **************************************************************************** #

NAME		=	phonebook
CPPFILES	=	phonebook.cpp phonebook.class.cpp contact.class.cpp
OBJDIR		=	objects
OFILES		=	$(CPPFILES:%.cpp=$(OBJDIR)/%.o)
OS      	=   $(shell uname)
ifeq ($(OS),Linux)
	CC		=	g++
else
	CC		=	clang++
endif
FLAGS		=	-Wall -Werror -Wextra -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJDIR) $(OFILES)
	$(CC) $(FLAGS) -o $(NAME) $(OFILES)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -rf $(OBJDIR)
	rm -f $(NAME)

re: fclean all

test: all
	@echo
	./$(NAME)
