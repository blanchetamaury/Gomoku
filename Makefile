CXX = c++

CXXFLAGS = -lSDL2 -lSDL2_image -lm -g

SRC = src/main.cpp ${GRAPHIC} ${ALGO}

GRAPHIC = src/graphic/init/init.cpp \
			src/graphic/init/texture/init_texture.cpp \
			src/graphic/init/map/map.cpp \
			src/graphic/init/player/player.cpp

ALGO = src/algo/rules/rules.cpp

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
