CXX = g++
CXXFLAGS = -Iinclude -std=c++11
LDFLAGS = -lSDL2main -lSDL2 -lSDL2_image -mconsole

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