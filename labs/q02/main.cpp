#include <iostream>
#include <format>
#include <print>
#include <string>
#include <string_view>
#include <vector>
#include <algorithm>

// C++23: 명시적 this 파라미터 (deducing this) 예제
struct Counter
{
    int value = 0;

    // C++23: deducing this
    auto& increment(this auto& self)
    {
        ++self.value;
        return self;
    }

    auto get(this const auto& self)
    {
        return self.value;
    }
};

int main()
{
    std::println("=== Q02: C++23 신규 기능 실습 ===");

    // C++23: deducing this
    Counter c;
    c.increment().increment().increment();
    std::println("Counter: {}", c.get());

    // C++23: std::string contains()
    std::string text = "Hello, C++23 World!";
    std::println("'C++23' 포함 여부: {}", text.contains("C++23"));

    // std::format 활용
    std::vector<std::string> items = {"apple", "banana", "cherry"};
    for (int i = 0; auto& item : items)
    {
        std::println("[{}] {}", i++, item);
    }

    return 0;
}
