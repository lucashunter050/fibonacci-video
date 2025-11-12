CXX = clang++
CXXFLAGS = -std=c++20 -O3 -march=native -Wall -Wextra

SRC = main.cpp fib_recursive.cpp
OBJ = $(SRC:.cpp=.o)

fib_bench: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) fib_bench
