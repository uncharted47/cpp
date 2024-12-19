Name = megaphone
SRC = Megaphone.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
all: $(Name)

$(Name): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(Name)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.SECONDARY: $(OBJ)
