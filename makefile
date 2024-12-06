# Define compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

# Target application. The final, compiled version of the game
TARGET = main

# The sources are needed to satisfy the linker and the compilation command
# Code will not compile unless ALL source files are used
SOURCES = src/main.cpp src/game.cpp src/maze.cpp
HEADERS = src/game.h src/maze.h

# Default to build app
all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean:
	rm -f $(TARGET)