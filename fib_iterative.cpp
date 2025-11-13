#include "fib.hpp"

big_int fib_iterative(uint64_t n)
{
    if (n == 0)
        return 0;
    big_int a = 0;
    big_int b = 1;
    for (uint64_t i = 2; i <= n; ++i)
    {
        big_int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}