Name = megaphone
SRC = Megaphone.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(Name)

$(Name): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(Name)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f megaphone

re: fclean all

.SECONDARY: $(OBJ)