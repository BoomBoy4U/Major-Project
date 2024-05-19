# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = game

# Source files
SRCS = main.cpp \
       Gameplay.cpp \
       Player.cpp \
       Entity.cpp \
       Enemy.cpp \
       Boss.cpp \
       GameMenu.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = Gameplay.h \
          Player.h \
          Entity.h \
          Enemy.h \
          Boss.h \
          GameMenu.h

# Default rule
all: $(TARGET)

# Rule to link the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
