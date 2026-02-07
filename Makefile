# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++17

# Target executable
TARGET = battleship

# Source files
SRCS = src/main.cpp src/board/board.cpp src/ship/ship.cpp src/utils/utils.cpp src/coordinate/coordinate.cpp

# Object files (replace .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Default rule: build the executable
all: $(TARGET)

# Link object files into the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files and executable
clean:
	rm -f $(OBJS) $(TARGET)
