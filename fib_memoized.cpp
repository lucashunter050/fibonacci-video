#include "fib.hpp"
#include <unordered_map>

uint64_t fib_memoized(uint64_t n) {
    static std::unordered_map<uint64_t, uint64_t> memo;
    if (n < 2) return n;
    if (memo.count(n)) return memo[n];
    return memo[n] = fib_memoized(n - 1) + fib_memoized(n - 2);
}
