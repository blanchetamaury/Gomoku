CXX = c++

CXXFLAGS = -lSDL2 -lSDL2_image -lm -g

SRC = src/main.cpp ${GRAPHIC}

GRAPHIC = src/graphic/init/init.cpp \
			src/graphic/init/texture/init_texture.cpp \

ALGO =

OBJ = $(SRC:%.cpp=%.o)

NAME = Gomoku

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $^ $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
