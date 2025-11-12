#include <iostream>
#include <chrono>
#include <string>
#include <functional>
#include <unordered_map>
#include "fib.hpp"

using FibFunc = std::function<uint64_t(uint64_t)>;

FibFunc get_strategy(const std::string &name)
{
    static const std::unordered_map<std::string, FibFunc> strategies = {
        {"recursive", fib_recursive},
        {"memoized", fib_memoized}};
    auto it = strategies.find(name);
    if (it != strategies.end())
    {
        return it->second;
    }
    throw std::invalid_argument("Unknown strategy: " + name);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <strategy> <n>\n";
        return 1;
    }

    std::string strategy = argv[1];
    uint64_t n = std::stoull(argv[2]);

    try
    {
        FibFunc fib = get_strategy(strategy);

        auto start = std::chrono::high_resolution_clock::now();
        uint64_t result = fib(n);
        auto end = std::chrono::high_resolution_clock::now();

        double elapsed_ms = std::chrono::duration<double, std::milli>(end - start).count();

        std::cout << "fib(" << n << ") = " << result << "\n";
        std::cout << "Strategy: " << strategy << " | Time: " << elapsed_ms << " ms\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}
