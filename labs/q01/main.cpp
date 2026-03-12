#include <iostream>
#include <format>
#include <print>
#include <vector>
#include <ranges>

int main()
{
    // C++23: std::println
    std::print("=== Q01: C++23 기본 실습 ===\n");

    // std::format (C++20, C++23에서도 사용)
    auto msg = std::format("현재 연도: {}", 2026);
    std::println("{}", msg);

    // C++23 ranges + views
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::print("짝수: ");
    for (int n : nums | std::views::filter([](int x) { return x % 2 == 0; }))
    {
        std::print("{} ", n);
    }
    std::println("");

    return 0;
}
