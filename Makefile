CXX = c++

CXXFLAGS = --lSDL2 -lSDL2_image -lm -g

SRC = src/main.cpp ${GRAPHIC}

GRAPHIC = init/init.cpp \
			init/init_texture.cpp \

ALGO =

OBJ = $(SRC:%.cpp=%.o)

NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $^ $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
