#include "fib.hpp"
#include <unordered_map>

big_int fib_memoized(uint64_t n)
{
    static std::unordered_map<uint64_t, big_int> memo;
    if (n < 2)
        return big_int(n);
    auto it = memo.find(n);
    if (it != memo.end())
        return it->second;
    big_int res = fib_memoized(n - 1) + fib_memoized(n - 2);
    memo[n] = res;
    return res;
}
