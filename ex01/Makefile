SRC = Contact.cpp Phonebook.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
CC = g++
RM = rm -f
INCLUDE = 	-I ./includes 
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic $(INCLUDE) 
# CPPFLAGS = $(INCLUDE) 

NAME = my_phonebook

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
