# Below is compiler and compilation flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Below Builds the rotorMachine program
all: rotorMachine

rotorMachine: rotorMachine.o Main.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Below compiles rotorMachine source file
rotorMachine.o: rotorMachine.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Below compiles Main source file
Main.o: Main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Below cleans up generated files
clean:
	rm -f rotorMachine *.o
