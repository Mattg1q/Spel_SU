CXX = g++
SDL_LIB_DIR = C:/Users/HEROB/scoop/apps/sdl2/current/lib
SDL_IMAGE_LIB_DIR = C:/Users/HEROB/scoop/apps/sdl2-image/current/lib

CXXFLAGS = -Iinclude -std=c++11
LDFLAGS = -L$(SDL_LIB_DIR) -L$(SDL_IMAGE_LIB_DIR) -lSDL2main -lSDL2 -lSDL2_image -mconsole

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = build/debug/game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)