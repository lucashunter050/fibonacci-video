#include "fib.hpp"

uint64_t fib_recursive(uint64_t n) {
    if (n <= 1) {
        return n;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}