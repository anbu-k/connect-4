# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Source files
SOURCES = main.cpp game.cpp board.cpp AI.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Executable
EXECUTABLE = connect4

# Build rules
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp Game.h Board.h AI.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: clean
