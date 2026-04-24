CXX = g++
CXXFLAGS = -Iinclude -std=c++11 -Wall
# Standardlänkning som fungerar på Linux/Mac/Windows (om miljön är rätt uppsatt)
LDFLAGS = -lSDL2main -lSDL2 -lSDL2_image

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = build/debug/game

all: $(TARGET)

$(TARGET): $(OBJ)
# Skapa mappen innan filen läggs där (fungerar i Linux/Mac och MinGW)
	mkdir -p build/debug 
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)