CXX = clang++
CXXFLAGS = -std=c++20 -O3 -march=native -Wall -Wextra -I/opt/homebrew/Cellar/boost/1.89.0/include

SRC = main.cpp fib_recursive.cpp fib_memoized.cpp
OBJ = $(SRC:.cpp=.o)

fib_bench: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) fib_bench
