#pragma once
#include <cstdint>
#include <boost/multiprecision/cpp_int.hpp>

using big_int = boost::multiprecision::cpp_int;

big_int fib_recursive(uint64_t n);
big_int fib_memoized(uint64_t n);
big_int fib_iterative(uint64_t n);