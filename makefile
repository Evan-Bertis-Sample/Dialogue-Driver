# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Iinclude

# Linker flags
LDFLAGS = 

# Source files
SRCS = $(wildcard src/*.cpp)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = driver

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean

run:
	$(EXEC)